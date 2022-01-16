//
//  main.cpp
//  Final.Pro
//
//  Created by Mersad MacBook on 10/12/1400 AP.
//
//
#include <iostream>
#include <string.h>
#include <curses.h>
#include <stdlib.h>
using namespace std;
//********************************************************************************************************************************
const int m=500;
long long int cart[m];
//********************************************************************************************************************************
class Buyer
{
    
    int buyerCode[m];
    string buyerName[m];
    string buyerNumber[m];
    int countB;
public:
    void Buyers()
    {
        countB=0;
    }
    void getbuyer();
    void displaybuyer();
    void displaySPbuyer();
};
void Buyer:: getbuyer()
{
    cout<<"Buyer code : ";
    cin>>buyerCode[countB];
    cout<<"Buyer name : ";
    cin>>buyerName[countB];
    cout<<"Buyer Number :";
    cin>>buyerNumber[countB];
    countB++;
    cout<<"***********************************************************************************************"<<endl;
}
void Buyer:: displaybuyer()
{
        cout<<"\n 1: Buyer_code  2: buyer_name  3: Buyer-Number  4: Buyer_Bascket   \n \n";
        for(int i=0 ; i<countB ; i++)
        {
                cout<<"1: "<<buyerCode[i]<<"\n";
                cout<<"2: "<<buyerName[i]<<"\n";
                cout<<"3: "<<buyerNumber[i]<<"\n";
                cout<<"4: "<<cart[i]<<"\n";
            
        }
        cout<<"\n";
        cout<<"***********************************************************************************************"<<endl;
}
void Buyer::displaySPbuyer()
{
    long long int min , max ;
    cout<<"Enter Max & Min : "<<endl;
    cin>>max>>min;
    cout<<"\n 1: Buyer_code  2: buyer_name  3: Buyer-Number   \n \n";
    for(int i=0 ; i<countB ; i++)
    {
        if (max>cart[i] && min<cart[i])
        {
                cout<<"1: "<<buyerCode[i]<<"\n";
                cout<<"2: "<<buyerName[i]<<"\n";
                cout<<"3: "<<buyerNumber[i]<<"\n";
        }
    }
    cout<<"\n";
    cout<<"***********************************************************************************************"<<endl;
}
//********************************************************************************************************************************
class Seller
{
    int sellerCode[m];
    string sellerName[m];
    string sellerAddress[m];
    string sellerNumber[m];
    int countS;
public:
    void Sellers()
    {
        countS=0;
    }
    void getseller();
    void displayseller();
    
};
void Seller::getseller()
{
    cout<<"Seller code : ";
    cin>>sellerCode[countS];
    cout<<"Seller name : ";
    cin>>sellerName[countS];
    cout<<"Seller Address : ";
    cin>>sellerAddress[countS];
    cout<<"Seller Number :";
    cin>>sellerNumber[countS];
    cout<<"***********************************************************************************************"<<endl;
    countS++;
}
void Seller ::displayseller()
{
    int scode;
    cout<<"Enter Seller Code : ";
    cin>>scode;
    cout<<"\n 1: Seller_Code  2: Seller_name  3: Seller_Address  4: Seller_Number\n \n";
    for(int i=0;i<countS;i++)
    {
        if (sellerCode[i]==scode )
        {
            cout<<"1: \t"<<sellerCode[i]<<"\n";
            cout<<"2: \t"<<sellerName[i]<<"\n";
            cout<<"3: \t"<<sellerAddress[i]<<"\n";
            cout<<"4: \t"<<sellerNumber[i]<<"\n";
        }
    }
    cout<<"\n";
    cout<<" ***********************************************************************************************"<<endl;
}
//********************************************************************************************************************************
class items
{
    int itemCode[m];
    string itemName[m];
    float itemPrice[m];
    int sellerCode[m];
    int numberOfItem[m];
    int count;
    public:
        void produce()
        {
            count = 0;
        }
        void getitem();
        void display();
        void remove();
        void displayItems();
        void displayAllitemt();
};
void items :: getitem()
{
    cout<<"item code : ";
    cin>>itemCode[count];
    cout<<"item name : ";
    cin>>itemName[count];
    cout<<"item price : ";
    cin>>itemPrice[count];
    cout<<"seller code : ";
    cin>>sellerCode[count];
    cout<<"number of item :";
    cin>>numberOfItem[count];
    cout<<"***********************************************************************************************"<<endl;
    count++;
}
void items :: remove()
{
    int icode,scode,bcode ,n , y , l;
    cout<<"Enter item code: ";
    cin >> icode;
    cout<<"Enter Seller Code : ";
    cin>>scode;
    cout<<"Enter Buyer Code : ";
    cin>>bcode;
    for(int i=0;i<count;i++)
       if(itemCode[i] == icode && sellerCode[i] == scode )
       {
           cout<<"Item Price : "<<"\t"<<itemPrice[i]<<endl;
           cout<<"Supply :  "<<numberOfItem[i]<<endl;
       }
    cout<<"How Many : ";
    cin>>n;
    for(int i=0;i<count;i++)
    {
       if(itemCode[i] == icode && sellerCode[i] == scode )
        if (n<=numberOfItem[i])
        {
            numberOfItem[i] -=n;
        }else {
            do
                    {
                cout<<"Stock Not Enogh  "<<endl;
                cout<<"Supply :  "<<numberOfItem[i]<<endl;
                cout<<"For Countinue On Buying Enter : 1    "<<"\n";
                cout<<"For Quit Enter : 2  "<<"\n";
                cout<<"\t \t  Chhice : "<<"\t";
                cin>>y;
                if (y==1)
                    {
                        cout<<"How Many : ";
                        cin>>l;
                        if (l<=numberOfItem[i])
                        {
                            numberOfItem[i] -=l;
                            break;
                        }else {
                            cout<<"Invalid Input\n";
                              }
                        
                    }else if (y==2)
                        {
                            break;
                        }
                    }while (y!=2);
            cart[i]=cart[i]+itemPrice[i]*n;
            }

    }
    cout<<"***********************************************************************************************"<<endl;
 }
 void items :: displayItems()
 {
     long long int max , min ;
     cout<<"Enter Max & Min : ";
     cin>>max>>min;

         cout<<"\n 1: item_Code  2: item_Name 3: item_Price 4: Seller_Code 5: number_Of_Item\n \n";
         for(int i=0;i<count;i++)
         {
             if (itemPrice[i]>=min & itemPrice[i]<=max )
             {
             cout<<"1: "<<itemCode[i]<<endl;
             cout<<"2: "<<itemName[i]<<endl;
             cout<<"3: "<<itemPrice[i]<<endl;
             cout<<"4: "<<sellerCode[i]<<endl;
             cout<<"5: "<<numberOfItem[i]<<endl;
            }
         cout<<"\n";
         cout<<"***********************************************************************************************"<<endl;
     }

 }
void items::displayAllitemt()
{
    cout<<"\n 1: item_Code  2: item_Name 3: item_Price 4: Seller_Code 5: number_Of_Item\n \n";
    for(int i=0;i<count;i++)
    {
        cout<<"1: "<<itemCode[i]<<endl;
        cout<<"2: "<<itemName[i]<<endl;
        cout<<"3: "<<itemPrice[i]<<endl;
        cout<<"4: "<<sellerCode[i]<<endl;
        cout<<"5: "<<numberOfItem[i]<<endl;
    cout<<"\n";
    cout<<"***********************************************************************************************"<<endl;
}
}
//********************************************************************************************************************************
int main()
{
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"<<  HELLO  FRIEND ...  >>"<<endl;
    cout<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    Welcome To My Sale System !   ";
    items order;
    order.produce();
    Seller add;
    add.Sellers();
    Buyer cost;
    cost.Buyers();
 int x , y , z , f ,w ;
 do{
     cout<<"\n How Can I Help You  ? ?      "<<endl;
     cout<<"Enter Your  Order \n";
     cout<<"\n1 : ADD  ";
     cout<<"\n2 : BUY  ";
     cout<<"\n3 : Display ";
     cout<<"\n4 : Quit";
     cout<<"\n\n Choice : ";
     cin>>y;
     system("clear");
     cout<<"***********************************************************************************************"<<endl;
     switch (y)
     {

         case 1 :
             cout<<"\n1 : Add  Seller ";
             cout<<"\n2 : Add  item  ";
             cout<<"\n3 : Add  Buyer ";
             cout<<"\n\n Choice : ";
             cin>>x;
             switch (x)
             {
                 case 1 :
                     add.getseller();
                     system("clear");
                     break;
                 case 2 :
                     order.getitem();
                      system("clear");
                     break;
                 case 3 :
                     cost.getbuyer();
                     system("clear");
                     break;
                     
                 default:
                     cout<<"Invalid Output\n"    ;
                     break;
             }
             break;
             
         case 2 :
             order.remove();
             system("clear");
             break;
             
         case 3 :
             cout<<"\n1 : Display  Items ";
             cout<<"\n2 : Display Seller ";
             cout<<"\n3 : Display Buyer  ";
             cout<<"\n\n Choice : ";
             cin>>z;
             switch (z)
             {
                 case 1 :
                     cout<<"\n 1: Display All Item  ";
                     cout<<"\n 2: Display Special Item ";
                     cout<<"\n\n Choice : ";
                     cin>>f;
                     switch (f)
                     {
                         case 1 :
                             order.displayAllitemt();
                             break;
                         case 2 :
                             order.displayItems();
                         default:
                             break;
                     }
                     break;
                 case 2 :
                     add.displayseller();
                     break;
                 case 3 :
                     cout<<"\n 1: Display All Buyer  ";
                     cout<<"\n 2: Display Special Buyer ";
                     cout<<"\n\n Choice : ";
                     cin>>w;
                     switch (w)
                     {
                         case 1 :
                             cost.displaybuyer();
                             break;
                         case 2 :
                             cost.displaySPbuyer();
                         default:
                             break;
                     }
                     break;
                     
                 default:
                     cout<<"Invalid Output\n"    ;
                     break;
             }
       default:
          cout<<"Invalid Output\n"    ;
             break;
        }
     }while(y!=4);
}
