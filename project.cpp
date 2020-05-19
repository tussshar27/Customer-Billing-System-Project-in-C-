#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;
class project
{
    public:
    string cname, pname[3];
    char cnum[10];
    int npro, pquantity[3], i, pprice[3], tprice[3], tgst[3];;
    void login();
    void input();
    void output();
    void gst();
};
void project :: login()
{

    string username="",password="",expectedUsername="admin",expectedPwd="777777";
    char ch;

    cout<<"Enter username:\n";
    cin>>username;

    cout<<"Enter password:\n";
    for(int i=0; i<6; i++)
    {
        ch=getch();
        password=password+ch;
        ch='*';
        cout << ch;
    }
    if(password.compare(expectedPwd)==0)
    {
        cout<<"\nLogin Successfull!";
        input();

    }
    else
    {
        cout<<"\nLogin failed!";
        exit(0);
    }


}
void project :: input()
{
    cout << "\nEnter Customer Name:" << endl;
    cin.clear();
    cin.ignore();
    getline(cin,cname);
    cout << "Enter Contact Number:" << endl;
    cin >> cnum;
    cout << "Enter Number of Products:" << endl;
    cin >> npro;
    for(i=0; i<npro; i++)
    {
        cout << "Enter Product Name:" << endl;
        cin >> pname[i];
        cout << "Enter Product Quantity:" << endl;
        cin >> pquantity[i];
        cout << "Enter Product Price:" << endl;
        cin >> pprice[i];
        tprice[i] = pquantity[i] * pprice[i];

    }
}
void project :: gst()
{
    for(i=0; i<npro; i++)
    {
        if(tprice[i]<=1000)
        {
            tgst[i] = tprice[i] + (tprice[i] * 0.05);       //5%
        }
        else
        {
            tgst[i]= tprice[i] + (tprice[i] * 0.1);     //10%
        }
    }
}
void project :: output()
{
    int tsum=0, pq=0, uc=0;
    cout << "\nProduct Name"<<"\t\t"<<"Quantity"<<"\t\t"<<"Price"<<"\t\t"<<"Price(+gst)" << endl;
    for(i=0; i<npro; i++)
    {
        cout << pname[i]<<"\t\t\t\t"<< pquantity[i]<<"\t\t\t\t"<< tprice[i] <<"\t\t\t\t"<< tgst[i]<< endl;
    }

    for(i=0; i<npro; i++)
    {
        tsum = tsum + tgst[i];
        pq = pq + pquantity[i];
    }
    cout << "\n-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-";
    cout << "\nTotal Quantity:\t" << pq << "\t\tTotal price:\t" << tsum;
    cout << "\n\nTotal Cash Given By Customer:";
    cin >> uc;
    cout << "\nCash To Be Repay To Customer:" << uc-tsum <<endl;
    cout << "-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-";
}
int main()
{
    int ch;
    /*
    project pr;
    pr.login();
    pr.gst();
    pr.output();
    return 0;*/
    project pr;
    //pr.login();

    cout<<"||Customer Billing System||"<<endl;
    cout<<"1. Create new bill"<<endl;
    cout<<"2. View previous bill"<<endl;
    cout<<"3. Exit:"<<endl;
    cout<<"Please enter an option: :"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        pr.login();
        pr.input();
        pr.gst();
        pr.output();
        break;
    case 2:
        //pr.login();
        //pr.preview();
        break;
    case 3:
        exit(0);
       // break;
    default:
        cout<<"Invalid Choice";
    }
    return 0;
}


