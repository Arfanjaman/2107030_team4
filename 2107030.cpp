#include <bits/stdc++.h>

using namespace std;

class Product {
    public:
   string product_name;
   float product_price;
   int quantity;
   
   Product(){
    product_name="Undefined";
    product_price=0;
    quantity=0;

   }
   void set_Product(string name,float price,int q){
   product_name=name;
   product_price=price; 
   quantity=q;
   }

 void display(){
    cout<<product_name<<"\t"<<product_price<<"\t\t"<<quantity<<"\n";
 }


};

class Brand{
    Product mal[100];
    int total,counter;
public:
    string b_name;
    Brand()
    {       b_name="Undefined";
            total=0;
            counter=0;

    }
    void set_Brand(string name){
        b_name=name;
       
    }


     void add_product(string s,float y, int x)
    {
        int ok;
        for(int l = 0; l < total; l++)
        {
            if(mal[l].product_name == s)
            {
                mal[l].quantity += x;
                ok = 1;
            }
        }
        if(ok != 1)
        {
            mal[counter].set_Product(s,y,x);
            counter++;
            total++;
        }
        ok = 0;
    }
    int del_product(string s, int x, int type)
    {
        int ok;
        for(int l = 0; l < total; l++)
        {
            if(mal[l].product_name == s)
            {
                if(mal[l].quantity >= x)
                {
                    mal[l].quantity -= x;
                    ok = 1;
                }
                else if(mal[l].quantity < x && type == 0)
                {
                    mal[l].quantity = 0;
                    ok = 1;
                }
            }
        }
        if(ok != 1)
        {
            cout << "Product out of stock/insufficient" << endl;
            return 0;
        }
    }
    void brand_display()
    {
        cout << endl;
        cout << "Brand Name: " << b_name << endl << endl;
        cout << "Product\tQuantity\tAmount" << endl;
        for (int i = 0; i < total; i++)
        {
            mal[i].display();
        }
    }
};
class bill
{
    int i;
    int total;
    string brand[1000];
    string product[1000];
    int quantity[1000];
    int amount[1000];
public:
    bill()
    {
        i = 0;
        total = 0;
    }
    void add_to_bill(string b, string p, int q, int a)
    {
        int ok;
        for(int n = 0; n < total; n++)
        {
            if(brand[n] == b && product[n] == p)
            {
                quantity[n] += q;
                ok = 1;
            }
        }
        if(ok != 1)
        {
            brand[i] = b;
            product[i] = p;
            quantity[i] = q;
            amount[i] = q * a;
            i++;
            total++;
        }
    }
    void show_bill()
    {
        for(int j = 0; j < total; j++)
        {
            cout << setw(30) << left << brand[j] << setw(30) << left << product[j] << setw(30) << left << quantity[j] << setw(25) << right << amount[j] << endl << endl;
        }
    }
};

class Owner{
    string owner_name;
    int password;
 public:
 Owner(){

 }
 void set_Owner(string name,int pass){
    owner_name=name;
    password=pass;
 }
 int return_pass(){
    return password;

 }
 string return_name(){
    return owner_name;
 }

};




class delivery{
 public:
    string address;
    int fee;
friend void show_bill();
delivery()
{

}
};





int main(){
   delivery adres;
   


Owner owner1;
bill bi;
 Brand b[100];
       int flag;
        int i=0;
       string brand, product;
        int quantity;
        float amount;
           string decision, addproduct, buyproduct,delproduct;
cout<<"Welcome to Automated Online Store\n";
cout<<"0.Owner\n";
       cout<<"1.Buyer\n";
   int choice1;
   cin>>choice1;
   while(!choice1){

if(choice1==0){
     cout<<"0. Owner Registration\n";
        cout<<"  1. Owner Login\n";
           int choice2;
           cin>>choice2;
           
            if(choice2==0){
            cout<<"Enter Your Name\n";
            string name1;
          cin>>name1;
            cin.ignore();
            cout<<"Enter Your Password\n";
            int pass1,pass2;
            cin>>pass1;
            cin.ignore();
            cout<<"Confirm Your Password\n";
            cin>>pass2; 
                    if(pass1!=pass2){
                        cout<<"Passwords Do not match\n";   
                                    }
                                else {
                           owner1.set_Owner(name1,pass2);

                    cout<<"Registered Successfully.\n";
                                    }
            }
        else if(choice2==1){
      
            cout<<"Owner Login\n" ;
                    cout<<"Enter Your Name:\n";
                    string name2;
                  cin>>name2;
                  cin.ignore();
                    cout<<"Enter Your Password:\n";
                    int pass3;
                    cin>>pass3;
                    if(name2!=owner1.return_name() || pass3!=owner1.return_pass()){
                        cout<<"Invalid Name or Password\n";
                      
                       }
                    
                       else{ cout<<"logged in Successfully\n";
                 
                        flag=1;
                         }
              
           
           }
           if(flag==1){
             cout<<"1.Add Product\n";
             cout<<"2.Delete Product\n";
             int choice3;
             cin>>choice3;
             while(choice3){
             if(choice3==1){
                cout << "Do you want to store more products?(Yes/No)" << endl;
        cin >> decision;
        if (decision == "Yes"){
                 cout << "State brand name: ";
            cin >> brand;
            b[i].set_Brand(brand);
            addproduct = "Yes";
            while (addproduct == "Yes")
            {
                cout << "State product name: ";
                cin >> product;
                cout << "State the standard amount of this product: ";
                cin >> amount;
                cout << "State quantity: ";
                cin >> quantity;
                b[i].add_product(product, amount, quantity);
                cout << "Do you want to add more products of this brand?(Yes/No)" << endl;
                cin >> addproduct;
            }
            i++;
        }
             }


        else{
            
            if(choice3==2){
                 int in;
            cout << "Do you want to delete products?(Yes/No)" << endl;
            cin >> decision;
            if(decision == "Yes")
         {
                cout << "Which brand of product do you want to delete?" << endl;
                cin >> brand;
                for(int m = 0; m < 100; m++)
                {
                    if(b[m].b_name == brand)
                    {
                        in = m;
                        break;
                    }
                }
                delproduct = "Yes";
                while(delproduct == "Yes")
                {
                    cout << "State product name: " << endl;
                    cin >> product;
                    cout << "State quantity: " << endl;
                    cin >> quantity;
                    b[in].del_product(product, quantity, 0);
                    cout << "Do you want to delete more products from the same brand?(Yes/No)" << endl;
                    cin >> delproduct;
                }




        }
                        }            }
            cout<<"1.Add Product\n";
             cout<<"2.Delete Product\n";
             cout<<"3.Exit\n";
             cin>>choice3;
             if(choice3==3){
                break;
             }
             
             }
         



           }
          


} 
  //cout << "Please select again: " << endl;
                cout << "0. Owner\n1. Buyer" << endl;
                cin >> choice1;

if(choice1==1){

     cout << "\t___Products available for purchase___" << endl << endl;
    for (int k = 0; k < i; k++)
    {
        b[k].brand_display();
    }
    i = 0;
    decision = "Yes";
    while(decision == "Yes")
    {
        int index, availability;
        string brand, product;
        int quantity, amount;
        cout << "State the brand of product that you want to buy: " << endl;
        cin >> brand;
        for(int m = 0; m < 100; m++)
        {
            if(b[m].b_name == brand)
            {
                index = m;
                break;
            }
        }
        buyproduct = "Yes";
        while(buyproduct == "Yes")
        {
            cout << "State the product name: " << endl;
            cin >> product;
            cout << "State the quantity: " << endl;
            cin >> quantity;
            availability = b[index].del_product(product, quantity, 1);
            if(availability) bi.add_to_bill(brand, product, quantity, amount);
            cout << "Do you want to buy more products from this brand?(Yes/No)" << endl;
            cin >> buyproduct;
        }
        cout << "Do you want to buy more?(Yes/No)" << endl;
        cin >> decision;
    }
     cout<<"Enter Your Delivery Location\n";
     string locate;
     cin>>locate;
     if(locate=="Khulna"){
        adres.fee=50;
     }
     else if(locate=="Dhaka"){
        adres.fee=100;
     }

    cout << "\n\n\n\n\n";
    cout << "Your Bill__________" << endl;
    bi.show_bill();
    cout<<"Delivery Fee\t"<<adres.fee;
    cout<<"Enter Payment Method\n";
    cout<<"1.Bkash\n";
    cout<<"2.Nagad\n";
    cout<<"3.Credit Card\n";
    cout<<"4.Cash On Delivery\n";
    int pm;
    cin>>pm;
    if(pm==1){
        cout<<"Enter Bkash phone Number\n";
        int num;
          cin>>num;
    cout<<"Paid succesfully\n";
    }
    else if(pm==2){
        cout<<"Enter Nagad phone Number\n";
        int num;
          cin>>num;
    cout<<"Paid succesfully\n";
    }
   
   else if(pm==3){
        cout<<"Enter Credit Cardn Number\n";
        int num;
          cin>>num;
    cout<<"Paid succesfully\n";
    }
    else if(pm==4)
{
    cout<<"Thank you for shoping with us\n";

}
cout<<"Thank You\n";
    return 0;
}
}


}      


