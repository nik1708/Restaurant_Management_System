/*
Required Improvements:
1. Amount to be returned negative.
2. Incorrect Bill No.
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <process.h>

using namespace std;
//Global Variables
int dito,fsq[254]={0},tfsq[254]={0},tn=1,bn=100,tbn=0,st,btn=0,s,mi,h,d,m,y,ta;
char nm[20],mn[10],fn[20];
int fsp[254]={};
char fs[254][50]={"Veg Sweetcorn Soup","Hot & Sour Soup","Mexican Soup","Tomato Soup","Manchow Soup","Tortilla Soup",
                 "Mix Veg Soup",//soup
                 "Panipuri (6 Pcs)","Bhelpuri","Sevpuri","Dahipuri","Chatnipuri","Masalapuri","Cheese Masalapuri",
                 "Samosa (2Pcs)","Samosa Chaat","Chole Samosa","Ragda Petish","Papdi Chaat","Samosa Pav",//Chat,
                 "Veg Burger","Cheese Burger","Veg Mayo Burger","Veg Sch Burger","Spl. Burger","Jain Burger"	,
                 "Oil Vadapav","Butter Vadapav","Cheese Vadapav","Butter Cheese Vadapav","Oil Cheese Vadapav",
                 "Jain Vadapav","Oil Dabeli" ,"Butter Dabeli","Cheese Dabeli","Veg Sandwich","Veg Grill Sandwich",
                 "Chesse Sandiwch","Veg Cheese Sandwich","Mexican Sandwich","Club Sandwich","Chole Bhature","Chole Kulche",
                 "Oil Bhaji Pav","Butter Bhaji Pav","Cheese Bhaji Pav","Masala Pav","Cheese Masala Pav",//fast food
                 "Idli","Masala Idli","Masala Dosa (oil)","Masala Dosa (butter)","Mysore Masala(oil)","Mysore Masala(bt)",
                 "Rawa Masala(oil)","Rawa Masala(bt)","Plain Garlic(oil)","Plain Garlic(bt)","Cheese Masala(oil)",
                 "Cheese Masala(bt)","Uttapam(oil)","Uttapam(bt)","Onion Uttapam(oil)","Onion Uttapam(bt)","Mix Uttapam(oil)",
                 "Mix Uttapam(bt)","Masala Uttapam(oil)","Masala Uttapam(bt)",//South Indian
                 "Veg. Quesadillas","Veg. Tacos","Veg. Enchiladas","Veg. Pinto Bean Salsa Salad","Veg. Mexican Lasagna",
                 "Nachos With Salsa","Veg Burritos",//Mexican
                 "Pesto","Alfredo","Arrabbita","Marinara","Garlic Bread Stix","Cheese Chilly Garlic Bread","Corn Garlic Bread",
                 "Garlic Bread Supreme","Stuffed Garlic Bread","Crunchy Strips","Potato Cheese Shots","Veg Parcel",//Italian
                 "Margarita[S]","Margarita[M]","Margarita[L]","Veg Farmhouse[S]","Veg Farmhouse[M]","Veg Farmhouse[L]","Veg Panner Makhani[S]",
                 "Veg Panner Makhani[M]","Veg Panner Makhani[L]","Veg Panner Tikka[S]","Veg Panner Tikka[M]",
                 "Veg Panner Tikka[L]","Veg Extravaganza[S]","Veg Extravaganza[M]","Veg Extravaganza[L]","Deluxe Veggie[S]",
                 "Deluxe Veggie[M]","Deluxe Veggie[L]","Mexican Green Wave[S]","Mexican Green Wave[M]","Mexican Green Wave[L]",
                 "Peppy Panner[S]","Peppy Panner[M]","Peppy Panner[L]","5 Pepper[S]","5 Pepper[M]","5 Pepper[L]",
                 "Veggie Paradise[S]","Veggie Paradise[M]","Veggie Paradise[L]","Fresh Veggie[S]","Fresh Veggie[M]",
                 "Fresh Veggie[L]","Corn & Chesse[S]","Corn & Chesse[M]","Corn & Chesse[L]","Double Chesse Margarita[S]",
                 "Double Chesse Margarita[M]","Double Chesse Margarita[L]",//pizza
                 "Veg Handi","Veg Kohlapuri","Panner Butter Masala","Cheese Butter Masala","Veg Jaipuri","Veg 65","Mix Veg",
                 "Kaju Butter Masala","Cheese Kaju Masala","Bhindi","Karela","Bharta","Dal Makhani","Dal Tadka","Plain Rice",
                 "Jeera Rice",//Punjabi
                 "Veg Manchurian Dry","Veg Manchurian Gravy","Veg Manchurian Rice","Veg Manchurian With Noodles",
                 "Veg Hakka Noodles","Veg Schezwan Noodles","Veg Manchow Noodles","Veg Paneer Chilly Dry",
                 "Veg Paneer Chilly Gravy","Veg Spring Roll","Veg Crispy",//Chinese
                 "Chinese Sizzler","Mexican Sizzler","Veg. Sizzler","Italian Sizzler","Momos Sizzler","Pasta Sizzler",
                 "Noodles Sizzler",//Sizzler
                 "Gujarati Thali","Punjabi Thali","Kathiyawadi Thali","South Indian Thali","Maharashtrian Thali","Bengali Thali",
                 //Special Thali
                 "Plain Chappati","Butter Chappati","Plain Tandoori Roti","Butter Tandoori Roti","Plain Naan","Butter Naan",
                 "Garlic Naan","Chur Chur Naan","Plain Kulcha","Butter Kulcha","Aloo Pyaaz Kulcha","Chur Chur Kulcha",
                 "Aloo Panner Kulcha","Amritsari Kulcha","Amritsari Panner Kulcha","Stuffed Kulcha","Pizza Kulcha",
                 "Mushroom Kulcha","Appam","Bhakhari","Roomali Roti","Aloo Paratha","Aloo Pyaaz Paratha","Paneer Paratha",
                 "Gobi Paratha","Mulli Paratha","Laccha Paratha","Tandoori Paratha",//Breads
                 "Gulabjamun","Rosogulla","Rasmalai","Kheer","Gajar ka Halwa","Mango Halwa","Mysore Pak","Indian Shrikhand",
                 "Milk Pudding","Fruit Salad","Puran Poli","Phirni","Vedmi","Kulfi","Jalebi","Rabdi","Rabdi with Jalebi",
                 "Vanilla Ice-Cream","Chocalate Ice-Cream","Strawberry Ice-Cream",//Desserts
                 "Water Bottle","Coke","Thumps Up","Pepsi","Mirinda","Fanta","Sprite","7 Up","Mountain Dew","Lemonade",
                 "Pina Colada","Mint Mojito","Strawbery Cocktail","Kiwi Avacado","Spicy Guava","Fusion Mint & Strawberry",
                 "Tea","Masala Tea","Black Tea","Green Tea","Ginger Tea","Lemon Tea","Honey Tea","Coffee","Black Coffee",
                 "Cappichino","Brewed Coffee","Frapichino","Cold Coffee","Cold Coffee w/I-C","Cold Coco","Cold Coco w/I-C",
                 "Cold Coco Coffee","Fruit Juices","Thandai","Roohafza","Oreo Thick Shake","Kaju Anjar Shake",
                 "Banana Milkshake","Guava Milkshake"//Beverages
                 };
//Global Function prototypes
void title();
void fl();//faster  speed empty  loop
void ml();//medium speed empty loop
void sl();//slow speed empty loop
void smily();//prints smiley
void fb();//choosing feedback
void feedback();//feedback  function
void bill();//bill function
void bfn();//creates bill file name
void sb();//to print saved bills
void payment(int);//payment options func
void pr(int);//prints payment receipt
void gb();
int randnum(int);//create random number using time
//Classes:-
class foodtype
{
public:
     void sm(int x)
{
    char b;
    switch(x)
    {
    case 1: cout<<"\n\tSoup          : a";
            break;
    case 2: cout<<"\n\tChat          : a";
            break;
    case 3: cout<<"\n\tFast Food     : a";
            break;
    case 4: cout<<"\n\tSouth Indian  : a";
            break;
    case 5: cout<<"\n\tMexican       : a";
            break;
    case 6: cout<<"\n\tItalian       : a";
            break;
    case 7: cout<<"\n\tPizza         : a";
            break;
    case 8: cout<<"\n\tPunjabi       : a";
            break;
    case 9: cout<<"\n\tChinese       : a";
            break;
    case 10: cout<<"\n\tSizzlers      : a";
            break;
    case 11: cout<<"\n\tSpecial Thali : a";
            break;
    case 12: cout<<"\n\tBread         : a";
            break;
    case 13: cout<<"\n\tDeserts       : a";
            break;
    case 14: cout<<"\n\tBeverages     : a";
            break;
    }
    cout<<"\n\tCuisines Menu : b";
    cout<<"\n\tBill          : c";
    cout<<"\n\n\tEnter Choice  : ";
    cin>>b;
    a:
    switch(b)
    {
        case 'b':system("cls");
                 ft();
                 break;
        case 'c':fb();
                 break;
        case 'a':system("cls");
            switch(x)
            {
            case 1:soup();
                   break;
            case 2:chat();
                   break;
            case 3:fastfood();
                   break;
            case 4:south();
                   break;
            case 5:mexican();
                   break;
            case 6:italian();
                   break;
            case 7:pizza();
                   break;
            case 8:punjabi();
                   break;
            case 9:chinese();
                   break;
            case 10:sizzlers();
                   break;
            case 11:spthali();
                   break;
            case 12:bread();
                   break;
            case 13:deserts();
                   break;
            case 14:beverages();
                   break;
            }
                 break;
        default: cout<<"\n\tInvalid Input !!\n\tPlease your choice again : ";
                 cin>>b;
                 goto a;
    }
}
    void ft()
{
    title();
    int b=0;
    cout<<"\n\n\n";
    cout<<"\t Types Of Cusines : "<<endl<<endl;
    cout<<"\t 01. Soup"<<endl;
    cout<<"\t 02. Chat"<<endl;
    cout<<"\t 03. Fast Food"<<endl;
    cout<<"\t 04. South Indian"<<endl;
    cout<<"\t 05. Mexican"<<endl;
    cout<<"\t 06. Italian"<<endl;
    cout<<"\t 07. Pizza"<<endl;
    cout<<"\t 08. Punjabi"<<endl;
    cout<<"\t 09. Chinese"<<endl;
    cout<<"\t 10. Sizzlers"<<endl;
    cout<<"\t 11. Special Thali"<<endl;
    cout<<"\t 12. Breads"<<endl;
    cout<<"\t 13. Deserts"<<endl;
    cout<<"\t 14. Beverages"<<endl;
    cout<<"\n\tEnter Your Choice : ";
    cin>>b;
    switch (b)
    {
    case 1:soup();
            break;
    case 2:chat();
           break;
    case 3:fastfood();
           break;
    case 4:south();
           break;
    case 5:mexican();
           break;
    case 6:italian();
           break;
    case 7:pizza();
           break;
    case 8:punjabi();
           break;
    case 9:chinese();
           break;
    case 10:sizzlers();
           break;
    case 11:spthali();
           break;
    case 12:bread();
            break;
    case 13:deserts();
           break;
    case 14:beverages();
           break;
    default :cout<<"\n\tInvalid Choice ";
             sl();
             system("cls");
             ft();
    }
}
void soup()
{
    int d=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tSOUP "<<"\n\n";
    cout<<"\tItem                         \t\t\tRate"<<"\n\n\n";
    cout<<"\t1. Veg Sweetcorn Soup        \t\t\t60/-\n";
    cout<<"\t2. Hot & Sour Soup           \t\t\t70/-\n";
    cout<<"\t3. Mexican Soup              \t\t\t70/-\n";
    cout<<"\t4. Tomato Soup               \t\t\t55/-\n";
    cout<<"\t5. Manchow Soup              \t\t\t65/-\n";
    cout<<"\t6. Tortilla Soup             \t\t\t70/-\n";
    cout<<"\t7. Mix Veg Soup              \t\t\t65/-";
    cout<<"\n\n\tSelect Your Food : ";
    cin>>d;
    switch(d)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[0];
               fsq[0]=fsq[0]+tfsq[0];
               fsp[0]=60;
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[1];
               fsq[1]=fsq[1]+tfsq[1];
               fsp[1]=70;
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[2];
               fsq[2]=fsq[2]+tfsq[2];
               fsp[2]=70;
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[3];
               fsq[3]=fsq[3]+tfsq[3];
               fsp[3]=55;
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[4];
               fsq[4]=fsq[4]+tfsq[4];
               fsp[4]=65;
               sm(1);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[5];
               fsq[5]=fsq[5]+tfsq[5];
               fsp[5]=70;
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[6];
               fsq[6]=fsq[6]+tfsq[6];
               fsp[6]=65;
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                soup();
    }sm(1);
}
void chat()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tCHAT "<<"\n\n";
    cout<<"\tItem                             \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Panipuri (6 Pcs)             \t\t\t20/-\n";
    cout<<"\t02. Bhelpuri                     \t\t\t30/-\n";
    cout<<"\t03. Sevpuri                      \t\t\t30/-\n";
    cout<<"\t04. Dahipuri                     \t\t\t40/-\n";
    cout<<"\t05. Chatnipuri                   \t\t\t35/-\n";
    cout<<"\t06. Masalapuri                   \t\t\t25/-\n";
    cout<<"\t07. Cheese Masalapuri            \t\t\t35/-\n";
    cout<<"\t08. Samosa (2Pcs)                \t\t\t20/-\n";
    cout<<"\t09. Samosa Chaat                 \t\t\t30/-\n";
    cout<<"\t10. Chole Samosa                 \t\t\t30/-\n";
    cout<<"\t11. Ragda Petish                 \t\t\t40/-\n";
    cout<<"\t12. Papdi Chaat                  \t\t\t30/-\n";
    cout<<"\t13. Samosa Pav                   \t\t\t15/-\n";
    cout<<"\n\n\tSelect Your Food : ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[7];
               fsq[7]=fsq[7]+tfsq[7];
               fsp[7]=20;
               sm(2);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[8];
               fsq[8]=fsq[8]+tfsq[8];
               fsp[8]=30;
               sm(2);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[9];
               fsq[9]=fsq[9]+tfsq[9];
               fsp[9]=30;
               sm(2);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[10];
               fsq[10]=fsq[10]+tfsq[10];
               fsp[10]=40;
               sm(2);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[11];
               fsq[11]=fsq[11]+tfsq[11];
               fsp[11]=35;
               sm(2);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[12];
               fsq[12]=fsq[12]+tfsq[12];
               fsp[12]=25;
               sm(2);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[13];
               fsq[13]=fsq[13]+tfsq[13];
               fsp[13]=35;
               sm(2);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[14];
               fsq[14]=fsq[14]+tfsq[14];
               fsp[14]=20;
               sm(2);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[15];
               fsq[15]=fsq[15]+tfsq[15];
               fsp[15]=30;
               sm(2);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[16];
               fsq[16]=fsq[16]+tfsq[16];
               fsp[16]=30;
               sm(2);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[17];
               fsq[17]=fsq[17]+tfsq[17];
               fsp[17]=40;
               sm(2);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[18];
               fsq[18]=fsq[18]+tfsq[18];
               fsp[18]=30;
               sm(2);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[19];
               fsq[19]=fsq[19]+tfsq[19];
               fsp[19]=15;
               sm(2);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                chat();
    }
}
void fastfood()
{
    int a=0;
    char d;
    system("cls");
    title();
    cout<<"\n\tFAST FOOD "<<"\n\n";
    cout<<"\tItem                         \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Veg Burger               \t\t\t40/-\n";
    cout<<"\t02. Cheese Burger            \t\t\t50/-\n";
    cout<<"\t03. Veg Mayo Burger          \t\t\t60/-\n";
    cout<<"\t04. Veg Sch Burger           \t\t\t75/-\n";
    cout<<"\t05. Spl. Burger              \t\t\t80/-\n";
    cout<<"\t06. Jain Burger              \t\t\t65/-\n";
    cout<<"\t07. Oil Vadapav              \t\t\t20/-\n";
    cout<<"\t08. Butter Vadapav           \t\t\t30/-\n";
    cout<<"\t09. Cheese Vadapav           \t\t\t35/-\n";
    cout<<"\t10. Butter Cheese Vadapav    \t\t\t40/-\n";
    cout<<"\t11. Oil Cheese Vadapav       \t\t\t30/-\n";
    cout<<"\t12. Jain Vadapav             \t\t\t25/-\n";
    cout<<"\t13. Oil Dabeli               \t\t\t20/-\n";
    cout<<"\t14. Butter Dabeli            \t\t\t25/-\n";
    cout<<"\t15. Cheese Dabeli            \t\t\t30/-\n";
    cout<<"\t16. Veg Sandwich             \t\t\t70/-\n";
    cout<<"\t17. Veg Grill Sandwich       \t\t\t85/-\n";
    cout<<"\t18. Chesse Sandiwch          \t\t\t90/-\n";
    cout<<"\t19. Veg Cheese Sandwich      \t\t\t100/-\n";
    cout<<"\t20. Mexican Sandwich         \t\t\t120/-\n";
    cout<<"\t21. Club Sandwich            \t\t\t120/-\n";
    cout<<"\t22. Chole Bhature            \t\t\t80/-\n";
    cout<<"\t23. Chole Kulche             \t\t\t75/-\n";
    cout<<"\t24. Oil Bhaji Pav            \t\t\t70/-\n";
    cout<<"\t25. Butter Bhaji Pav         \t\t\t85/-\n";
    cout<<"\t26. Cheese Bhaji Pav         \t\t\t95/-\n";
    cout<<"\t27. Masala Pav               \t\t\t50/-\n";
    cout<<"\t28. Cheese Masala Pav        \t\t\t60/-\n";
    cout<<"\n\n\tSelect Your Food : ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[20];
               fsq[20]=fsq[20]+tfsq[20];
               fsp[20]=40;
               sm(3);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[21];
               fsq[21]=fsq[21]+tfsq[21];
               fsp[21]=50;
               sm(3);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[22];
               fsq[22]=fsq[22]+tfsq[22];
               fsp[22]=60;
               sm(3);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[23];
               fsq[23]=fsq[23]+tfsq[23];
               fsp[23]=75;
               sm(3);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[24];
               fsq[24]=fsq[24]+tfsq[24];
               fsp[24]=80;
               sm(3);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[25];
               fsq[25]=fsq[25]+tfsq[25];
               fsp[25]=65;
               sm(3);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[26];
               fsq[26]=fsq[26]+tfsq[26];
               fsp[26]=20;
               sm(3);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[27];
               fsq[27]=fsq[27]+tfsq[27];
               fsp[27]=30;
               sm(3);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[28];
               fsq[28]=fsq[28]+tfsq[28];
               fsp[28]=35;
               sm(3);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[29];
               fsq[29]=fsq[29]+tfsq[29];
               fsp[29]=40;
               sm(3);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[30];
               fsq[30]=fsq[30]+tfsq[30];
               fsp[30]=30;
               sm(3);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[31];
               fsq[31]=fsq[31]+tfsq[31];
               fsp[31]=25;
               sm(3);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[32];
               fsq[32]=fsq[32]+tfsq[32];
               fsp[32]=20;
               sm(3);
               break;
        case 14:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[33];
               fsq[33]=fsq[33]+tfsq[33];
               fsp[33]=25;
               sm(3);
               break;
        case 15:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[34];
               fsq[34]=fsq[34]+tfsq[34];
               fsp[34]=30;
               sm(3);
               break;
        case 16:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[35];
               fsq[35]=fsq[35]+tfsq[35];
               fsp[35]=70;
               sm(3);
               break;
        case 17:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[36];
               fsq[36]=fsq[36]+tfsq[36];
               fsp[36]=85;
               sm(3);
               break;
        case 18:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[37];
               fsq[37]=fsq[37]+tfsq[37];
               fsp[37]=90;
               sm(3);
               break;
        case 19:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[38];
               fsq[38]=fsq[38]+tfsq[38];
               fsp[38]=100;
               sm(3);
               break;
        case 20:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[39];
               fsq[39]=fsq[39]+tfsq[39];
               fsp[39]=120;
               sm(3);
               break;
        case 21:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[40];
               fsq[40]=fsq[40]+tfsq[40];
               fsp[40]=120;
               sm(3);
               break;
        case 22:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[41];
               fsq[41]=fsq[41]+tfsq[41];
               fsp[41]=80;
               sm(3);
               break;
        case 23:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[42];
               fsq[42]=fsq[42]+tfsq[42];
               fsp[42]=75;
               sm(3);
               break;
        case 24:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[43];
               fsq[43]=fsq[43]+tfsq[43];
               fsp[43]=70;
               sm(3);
               break;
        case 25:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[44];
               fsq[44]=fsq[44]+tfsq[44];
               fsp[44]=85;
               sm(3);
               break;
        case 26:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[45];
               fsq[45]=fsq[45]+tfsq[45];
               fsp[45]=95;
               sm(3);
               break;
        case 27:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[46];
               fsq[46]=fsq[46]+tfsq[46];
               fsp[46]=50;
               sm(3);
               break;
        case 28:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[47];
               fsq[47]=fsq[47]+tfsq[47];
               fsp[47]=60;
               sm(3);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                fastfood();
    }
}
void south()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tSOUTH INDIAN "<<"\n\n";
    cout<<"\tItem                         \t\t\tRate"<<"\n\n";
    cout<<"\t01. Idli (6 Pcs)             \t\t\t30/-\n";
    cout<<"\t02. Masala Idli              \t\t\t40/-\n";
    cout<<"\t03. Masala Dosa (oil)        \t\t\t80/-\n";
    cout<<"\t04. Masala Dosa (butter)     \t\t\t100/-\n";
    cout<<"\t05. Mysore Masala(oil)       \t\t\t120/-\n";
    cout<<"\t06. Mysore Masala(bt)        \t\t\t140/-\n";
    cout<<"\t07. Rawa Masala(oil)         \t\t\t140/-\n";
    cout<<"\t08. Rawa Masala(bt)          \t\t\t160/-\n";
    cout<<"\t09. Plain Garlic(oil)        \t\t\t40/-\n";
    cout<<"\t10. Plain Garlic(bt)         \t\t\t50/-\n";
    cout<<"\t11. Cheese Masala(oil)       \t\t\t95/-\n";
    cout<<"\t12. Cheese Masala(bt)        \t\t\t105/-\n";
    cout<<"\t13. Uttapam(oil)             \t\t\t80/-\n";
    cout<<"\t14. Uttapam(bt)              \t\t\t95/-\n";
    cout<<"\t15. Onion Uttapam(oil)       \t\t\t100/-\n";
    cout<<"\t16. Onion Uttapam(bt)        \t\t\t120/-\n";
    cout<<"\t17. Mix Uttapam(oil)         \t\t\t130/-\n";
    cout<<"\t18. Mix Uttapam(bt)          \t\t\t145/-\n";
    cout<<"\t19. Masala Uttapam(oil)      \t\t\t100/-\n";
    cout<<"\t20. Masala Uttapam(bt)       \t\t\t110/-\n";
    cout<<"\n\n\tSelect Your Food : ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[48];
               fsq[48]=fsq[48]+tfsq[48];
               fsp[48]=30;
               sm(4);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[49];
               fsq[49]=fsq[49]+tfsq[49];
               fsp[49]=40;
               sm(4);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[50];
               fsq[50]=fsq[50]+tfsq[50];
               fsp[50]=80;
               sm(4);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[51];
               fsq[51]=fsq[51]+tfsq[51];
               fsp[51]=100;
               sm(4);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[52];
               fsq[52]=fsq[52]+tfsq[52];
               fsp[52]=120;
               sm(4);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[53];
               fsq[53]=fsq[53]+tfsq[53];
               fsp[53]=140;
               sm(4);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[54];
               fsq[54]=fsq[54]+tfsq[54];
               fsp[54]=140;
               sm(4);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[55];
               fsq[55]=fsq[55]+tfsq[55];
               fsp[55]=160;
               sm(4);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[56];
               fsq[56]=fsq[56]+tfsq[56];
               fsp[56]=40;
               sm(4);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[57];
               fsq[57]=fsq[57]+tfsq[57];
               fsp[57]=50;
               sm(4);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[58];
               fsq[58]=fsq[58]+tfsq[58];
               fsp[58]=95;
               sm(4);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[59];
               fsq[59]=fsq[59]+tfsq[59];
               fsp[59]=105;
               sm(4);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[60];
               fsq[60]=fsq[60]+tfsq[60];
               fsp[60]=80;
               sm(4);
               break;
        case 14:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[61];
               fsq[61]=fsq[61]+tfsq[61];
               fsp[61]=95;
               sm(4);
               break;
        case 15:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[62];
               fsq[62]=fsq[62]+tfsq[62];
               fsp[62]=100;
               sm(4);
               break;
        case 16:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[63];
               fsq[63]=fsq[63]+tfsq[63];
               fsp[63]=120;
               sm(4);
               break;
        case 17:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[64];
               fsq[64]=fsq[64]+tfsq[64];
               fsp[64]=130;
               sm(4);
               break;
        case 18:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[65];
               fsq[65]=fsq[65]+tfsq[65];
               fsp[65]=145;
               sm(4);
               break;
        case 19:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[66];
               fsq[66]=fsq[66]+tfsq[66];
               fsp[66]=100;
               sm(4);
               break;
        case 20:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[67];
               fsq[67]=fsq[67]+tfsq[67];
               fsp[67]=110;
               sm(4);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                south();
    }
}
void mexican()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tMEXICAN "<<"\n\n";
    cout<<"\tItem                         \t\t\tRate"<<"\n\n\n";
    cout<<"\t1. Veg Quesadilas            \t\t\t150/-\n";
    cout<<"\t2. Veg Tacos                 \t\t\t125/-\n";
    cout<<"\t3. Enchiladas                \t\t\t170/-\n";
    cout<<"\t4. Veg Pinto Bean Salsa Salad\t\t\t200/-\n";
    cout<<"\t5. Veg Mexican Lasagna       \t\t\t190/-\n";
    cout<<"\t6. Nachos With Salsa         \t\t\t175/-\n";
    cout<<"\t7. Veg Burritoss             \t\t\t50/-";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[68];
               fsq[68]=fsq[68]+tfsq[68];
               fsp[68]=150;
               sm(5);
               break;
        case 2:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[69];
               fsq[69]=fsq[69]+tfsq[69];
               fsp[69]=125;
               sm(5);
               break;
        case 3:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[70];
               fsq[70]=fsq[70]+tfsq[70];
               fsp[70]=170;
               sm(5);
               break;
        case 4:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[71];
               fsq[71]=fsq[71]+tfsq[71];
               fsp[71]=200;
               sm(5);
               break;
        case 5:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[72];
               fsq[72]=fsq[72]+tfsq[72];
               fsp[72]=190;
               sm(5);
               break;
        case 6:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[73];
               fsq[73]=fsq[73]+tfsq[73];
               fsp[73]=175;
               sm(5);
               break;
        case 7:cout<<"\n\tEnter Quantity ";
               cin>>tfsq[74];
               fsq[74]=fsq[74]+tfsq[74];
               fsp[74]=150;
               sm(5);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                mexican();
    }
}
void italian()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tITALIAN "<<"\n\n";
    cout<<"\tItem                          \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Pesto 	                   \t\t170/-\n";
    cout<<"\t02. Alfredo                   \t\t\t190/-\n";
    cout<<"\t03. Arrabbita                 \t\t\t200/-\n";
    cout<<"\t04. Marinara		           \t\t220/-\n";
    cout<<"\t05. Garlic Bread Stix	       \t\t\t70/-\n";
    cout<<"\t06. Cheese Chilly Garlic Bread\t\t\t80/-\n";
    cout<<"\t07. Corn Garlic Bread         \t\t\t80/-\n";
    cout<<"\t08. Garlic Bread Supreme      \t\t\t100/-\n";
    cout<<"\t09. Stuffed Garlic Bread 	   \t\t140/-\n";
    cout<<"\t10. Crunchy Strips            \t\t\t60/-\n";
    cout<<"\t11. Potato Cheese Shots       \t\t\t60/-\n";
    cout<<"\t12. Veg Parcel		           \t\t35/-\n";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[75];
               fsq[75]=fsq[75]+tfsq[75];
               fsp[75]=170;
               sm(6);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[76];
               fsq[76]=fsq[76]+tfsq[76];
               fsp[76]=190;
               sm(6);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[77];
               fsq[77]=fsq[77]+tfsq[77];
               fsp[77]=200;
               sm(6);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[78];
               fsq[78]=fsq[78]+tfsq[78];
               fsp[78]=220;
               sm(6);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[79];
               fsq[79]=fsq[79]+tfsq[79];
               fsp[79]=70;
               sm(6);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[80];
               fsq[80]=fsq[80]+tfsq[80];
               fsp[80]=80;
               sm(6);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[81];
               fsq[81]=fsq[81]+tfsq[81];
               fsp[81]=80;
               sm(6);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[82];
               fsq[82]=fsq[82]+tfsq[82];
               fsp[82]=100;
               sm(6);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[83];
               fsq[83]=fsq[83]+tfsq[83];
               fsp[83]=139;
               sm(6);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[84];
               fsq[84]=fsq[84]+tfsq[84];
               fsp[84]=60;
               sm(6);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[85];
               fsq[85]=fsq[85]+tfsq[85];
               fsp[85]=60;
               sm(6);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[86];
               fsq[86]=fsq[86]+tfsq[86];
               fsp[86]=35;
               sm(6);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                italian();
    }
}
void pizza()
{
    int a=0;
    char c,d;
    system("cls");
    title();
    cout<<"\n\tPIZZA "<<"\n\n";
    cout<<"\tItem                          \t\t\tS\tM\tL"<<"\n\n\n";
    cout<<"\t01. Margarita	               \t\t\t99\t195\t395/-\n";
    cout<<"\t02. Veg Farmhouse             \t\t\t205\t385\t595/-\n";
    cout<<"\t03. Veg Panner Makhani		   \t\t205\t385\t595/-\n";
    cout<<"\t04. Veg Panner Tikka 		   \t\t210\t400\t620/-\n";
    cout<<"\t05. Veg Extravaganza		   \t\t235\t450\t695/-\n";
    cout<<"\t06. Deluxe Veggie		       \t\t235\t450\t695/-\n";
    cout<<"\t07. Mexican Green Wave		   \t\t205\t385\t595/-\n";
    cout<<"\t08. Peppy Panner		       \t\t205\t385\t595/-\n";
    cout<<"\t09. 5 Pepper		           \t\t235\t450\t695/-\n";
    cout<<"\t10. Veggie Paradise		   \t\t205\t385\t595/-\n";
    cout<<"\t11. Fresh Veggie		       \t\t165\t305\t495/-\n";
    cout<<"\t12. Corn & Chesse	           \t\t165\t305\t495/-\n";
    cout<<"\t13. Double Chesse Margarita   \t\t\t165\t305\t495/-";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[87];
                       fsp[87]=99;
                       fsq[87]=fsq[87]+tfsq[87];break;
               case'm':cin>>tfsq[88];
                       fsp[88]=195;
                       fsq[88]=fsq[88]+tfsq[88];break;
               case'l':cin>>tfsq[89];
                       fsp[89]=395;
                       fsq[89]=fsq[89]+tfsq[89];break;
               default:cout<<"Invalid Input!!";
                       ml();
               pizza();
               }
               break;
        case 2:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[90];
                       fsp[90]=205;
                       fsq[90]=fsq[90]+tfsq[90];break;
               case'm':cin>>tfsq[91];
                       fsp[91]=385;
                       fsq[91]=fsq[91]+tfsq[91];break;
               case'l':cin>>tfsq[92];
                       fsp[92]=595;
                       fsq[92]=fsq[92]+tfsq[92];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 3:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[93];
                       fsp[93]=205;
                       fsq[93]=fsq[93]+tfsq[93];break;
               case'm':cin>>tfsq[94];
                       fsp[94]=385;
                       fsq[94]=fsq[94]+tfsq[94];break;
               case'l':cin>>tfsq[95];
                       fsp[95]=595;
                       fsq[95]=fsq[95]+tfsq[95];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 4:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[96];
                       fsp[96]=210;
                       fsq[96]=fsq[96]+tfsq[96];break;
               case'm':cin>>tfsq[97];
                       fsp[97]=400;
                       fsq[97]=fsq[97]+tfsq[97];break;
               case'l':cin>>tfsq[98];
                       fsp[98]=620;
                       fsq[98]=fsq[98]+tfsq[98];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 5:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[99];
                       fsp[99]=235;
                       fsq[99]=fsq[99]+tfsq[99];break;
               case'm':cin>>tfsq[100];
                       fsp[100]=450;
                       fsq[100]=fsq[100]+tfsq[100];break;
               case'l':cin>>tfsq[101];
                       fsp[101]=695;
                       fsq[101]=fsq[101]+tfsq[101];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 6:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[102];
                       fsp[102]=235;
                       fsq[102]=fsq[102]+tfsq[102];break;
               case'm':cin>>tfsq[103];
                       fsp[103]=450;
                       fsq[103]=fsq[103]+tfsq[103];break;
               case'l':cin>>tfsq[104];
                       fsp[104]=695;
                       fsq[104]=fsq[104]+tfsq[104];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 7:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[105];
                       fsp[105]=205;
                       fsq[105]=fsq[105]+tfsq[105];break;
               case'm':cin>>tfsq[106];
                       fsp[106]=385;
                       fsq[106]=fsq[106]+tfsq[106];break;
               case'l':cin>>tfsq[107];
                       fsp[107]=595;
                       fsq[107]=fsq[107]+tfsq[107];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 8:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[108];
                       fsp[108]=205;
                       fsq[108]=fsq[108]+tfsq[108];break;
               case'm':cin>>tfsq[109];
                       fsp[109]=385;
                       fsq[109]=fsq[109]+tfsq[109];break;
               case'l':cin>>tfsq[110];
                       fsp[110]=595;
                       fsq[110]=fsq[110]+tfsq[110];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 9:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[111];
                       fsp[111]=235;
                       fsq[111]=fsq[111]+tfsq[111];break;
               case'm':cin>>tfsq[112];
                       fsp[112]=450;
                       fsq[112]=fsq[112]+tfsq[112];break;
               case'l':cin>>tfsq[113];
                       fsp[113]=695;
                       fsq[113]=fsq[113]+tfsq[113];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 10:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[114];
                       fsp[114]=205;
                       fsq[114]=fsq[114]+tfsq[114];break;
               case'm':cin>>tfsq[115];
                       fsp[115]=385;
                       fsq[115]=fsq[115]+tfsq[115];break;
               case'l':cin>>tfsq[116];
                       fsp[116]=595;
                       fsq[116]=fsq[116]+tfsq[116];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 11:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
              case's':cin>>tfsq[117];
                       fsp[117]=165;
                       fsq[117]=fsq[117]+tfsq[117];break;
               case'm':cin>>tfsq[118];
                       fsp[118]=305;
                       fsq[118]=fsq[118]+tfsq[118];break;
               case'l':cin>>tfsq[119];
                       fsp[119]=495;
                       fsq[119]=fsq[119]+tfsq[119];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
        case 12:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[120];
                       fsp[120]=165;
                       fsq[120]=fsq[120]+tfsq[120];break;
               case'm':cin>>tfsq[121];
                       fsp[121]=305;
                       fsq[121]=fsq[121]+tfsq[121];break;
               case'l':cin>>tfsq[122];
                       fsp[122]=495;
                       fsq[122]=fsq[122]+tfsq[122];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }
               break;
         case 13:
               cout<<"\tSmall: 's' Medium: 'm' Large: 'l'";
               cout<<"\n\tEnter Size: ";
               cin>>d;
               cout<<"\n\tEnter Quantity : ";
               switch(d)
               {
               case's':cin>>tfsq[123];
                       fsp[123]=165;
                       fsq[123]=fsq[123]+tfsq[123];break;
               case'm':cin>>tfsq[124];
                       fsp[124]=305;
                       fsq[124]=fsq[124]+tfsq[124];break;
               case'l':cin>>tfsq[125];
                       fsp[125]=495;
                       fsq[125]=fsq[125]+tfsq[125];break;
               default:cout<<"Invalid Input!!";
               ml();
               pizza();
               }

               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                pizza();
    }sm(7);
}
void punjabi()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tPUNJABI"<<"\n\n";
    cout<<"\tItem                           \t\t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Veg Handi	                \t\t\t110/-\n";
    cout<<"\t02. Veg Kohlapuri	            \t\t\t120/-\n";
    cout<<"\t03. Panner Butter Masala	    \t\t\t135/-\n";
    cout<<"\t04. Cheese Butter Masala	    \t\t\t150/-\n";
    cout<<"\t05. Veg Jaipuri	            \t\t\t\t110/-\n";
    cout<<"\t06. Veg 65	                    \t\t\t65/-\n";
    cout<<"\t07. Mix Veg	                \t\t\t130/-\n";
    cout<<"\t08. Kaju Butter Masala	        \t\t\t140/-\n";
    cout<<"\t09. Cheese Kaju Masala         \t\t\t\t150/-\n";
    cout<<"\t10. Bhindi                     \t\t\t\t120/-\n";
    cout<<"\t11. Karela	                    \t\t\t125/-\n";
    cout<<"\t12. Bharta	                    \t\t\t130/-\n";
    cout<<"\t13. Dal Makhani	            \t\t\t\t140/-\n";
    cout<<"\t14. Dal Tadka                  \t\t\t\t150/-\n";
    cout<<"\t15. Plain Rice                 \t\t\t\t120/-\n";
    cout<<"\t16. Jeera Rice	                \t\t\t125/-\n";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[126];
               fsq[126]=fsq[126]+tfsq[126];
               fsp[126]=110;
               sm(8);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[127];
               fsq[127]=fsq[127]+tfsq[127];
               fsp[127]=120;
               sm(8);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[128];
               fsq[128]=fsq[128]+tfsq[128];
               fsp[128]=135;
               sm(8);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[129];
               fsq[129]=fsq[129]+tfsq[129];
               fsp[129]=150;
               sm(8);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[130];
               fsq[130]=fsq[130]+tfsq[130];
               fsp[130]=110;
               sm(8);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[131];
               fsq[131]=fsq[131]+tfsq[131];
               fsp[131]=65;
               sm(8);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[132];
               fsq[132]=fsq[132]+tfsq[132];
               fsp[132]=130;
               sm(8);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[133];
               fsq[133]=fsq[133]+tfsq[133];
               fsp[133]=140;
               sm(8);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[134];
               fsq[134]=fsq[134]+tfsq[134];
               fsp[134]=150;
               sm(8);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[135];
               fsq[135]=fsq[135]+tfsq[135];
               fsp[135]=120;
               sm(8);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[136];
               fsq[136]=fsq[136]+tfsq[136];
               fsp[136]=125;
               sm(8);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[137];
               fsq[137]=fsq[137]+tfsq[137];
               fsp[137]=130;
               sm(8);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[138];
               fsq[138]=fsq[138]+tfsq[138];
               fsp[138]=140;
               sm(8);
               break;
        case 14:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[139];
               fsq[139]=fsq[139]+tfsq[139];
               fsp[139]=150;
               sm(8);
               break;
        case 15:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[140];
               fsq[140]=fsq[140]+tfsq[140];
               fsp[140]=120;
               sm(8);
               break;
        case 16:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[141];
               fsq[141]=fsq[141]+tfsq[141];
               fsp[141]=125;
               sm(8);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                punjabi();
    }
}
void chinese()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tCHINESE "<<"\n\n";
    cout<<"\tItem                           \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Veg Manchurian Dry         \t\t\t90/-\n";
    cout<<"\t02. Veg Manchurian Gravy       \t\t\t100/-\n";
    cout<<"\t03. Veg Manchurian Rice        \t\t\t110/-\n";
    cout<<"\t04. Veg Manchurian With Noodles\t\t\t120/-\n";
    cout<<"\t05. Veg Hakka Noodles          \t\t\t150/-\n";
    cout<<"\t06. Veg Schezwan Noodles       \t\t\t150/-\n";
    cout<<"\t07. Veg Manchow Noodles        \t\t\t140/-\n";
    cout<<"\t08. Veg Paneer Chilly Dry      \t\t\t110/-\n";
    cout<<"\t09. Veg Paneer Chilly Gravy    \t\t\t120/-\n";
    cout<<"\t10. Veg Spring Roll            \t\t\t90/-\n";
    cout<<"\t11. Veg Crispy                 \t\t\t100/-";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[142];
               fsq[142]=fsq[142]+tfsq[142];
               fsp[142]=90;
               sm(9);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[143];
               fsq[143]=fsq[143]+tfsq[143];
               fsp[143]=100;
               sm(9);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[144];
               fsq[144]=fsq[144]+tfsq[144];
               fsp[144]=110;
               sm(9);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[145];
               fsq[145]=fsq[145]+tfsq[145];
               fsp[145]=120;
               sm(9);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[146];
               fsq[146]=fsq[146]+tfsq[146];
               fsp[146]=150;
               sm(9);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[147];
               fsq[147]=fsq[147]+tfsq[147];
               fsp[147]=150;
               sm(9);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[148];
               fsq[148]=fsq[148]+tfsq[148];
               fsp[148]=140;
               sm(9);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[149];
               fsq[149]=fsq[149]+tfsq[149];
               fsp[149]=110;
               sm(9);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[150];
               fsq[150]=fsq[150]+tfsq[150];
               fsp[150]=120;
               sm(9);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[151];
               fsq[151]=fsq[151]+tfsq[151];
               fsp[151]=90;
               sm(9);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[152];
               fsq[152]=fsq[152]+tfsq[152];
               fsp[152]=100;
               sm(9);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                chinese();
    }
}
void sizzlers()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tSIZZLERS "<<"\n\n";
    cout<<"\tItem                           \t\t\tRate"<<"\n\n\n";
    cout<<"\t1. Chinese Sizzler             \t\t\t150/-\n";
    cout<<"\t2. Mexican Sizzler             \t\t\t180/-\n";
    cout<<"\t3. Veg. Sizzler                \t\t\t170/-\n";
    cout<<"\t4. Italian Sizzler             \t\t\t190/-\n";
    cout<<"\t5. Momos Sizzler               \t\t\t200/-\n";
    cout<<"\t6. Pasta Sizzler               \t\t\t185/-\n";
    cout<<"\t7. Noodles Sizzler             \t\t\t165/-\n";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[153];
               fsq[153]=fsq[153]+tfsq[153];
               fsp[153]=150;
               sm(10);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[154];
               fsq[154]=fsq[154]+tfsq[154];
               fsp[154]=180;
               sm(10);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[155];
               fsq[155]=fsq[155]+tfsq[155];
               fsp[155]=170;
               sm(10);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[156];
               fsq[156]=fsq[156]+tfsq[156];
               fsp[156]=190;
               sm(10);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[157];
               fsq[157]=fsq[157]+tfsq[157];
               fsp[157]=200;
               sm(10);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[158];
               fsq[158]=fsq[158]+tfsq[158];
               fsp[158]=185;
               sm(10);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[159];
               fsq[159]=fsq[159]+tfsq[159];
               fsp[159]=165;
               sm(10);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                sizzlers();
    }
}
void spthali()
{
    int a=0;
    char c;
    spt:
    system("cls");
    title();
    cout<<"\n\tSPECIAL THALI "<<"\n\n";
    cout<<"\tItem                           \t\t\tRate"<<"\n\n\n";
    cout<<"\t1. Gujarati Thali              \t\t\t140/-\n";
    cout<<"\t2. Punjabi Thali               \t\t\t160/-\n";
    cout<<"\t3. Kathiyawadi Thali           \t\t\t150/-\n";
    cout<<"\t4. South Indian Thali          \t\t\t160/-\n";
    cout<<"\t5. Maharashtrian Thali         \t\t\t150/-\n";
    cout<<"\t6. Bengali Thali               \t\t\t165/-\n";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[160];
               fsq[160]=fsq[160]+tfsq[160];
               fsp[160]=140;
               sm(11);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[161];
               fsq[161]=fsq[161]+tfsq[161];
               fsp[161]=160;
               sm(11);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[162];
               fsq[162]=fsq[162]+tfsq[162];
               fsp[162]=150;
               sm(11);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[163];
               fsq[163]=fsq[163]+tfsq[163];
               fsp[163]=160;
               sm(11);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[164];
               fsq[164]=fsq[164]+tfsq[164];
               fsp[164]=150;
               sm(11);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[165];
               fsq[165]=fsq[165]+tfsq[165];
               fsp[165]=165;
               sm(11);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                spthali();
    }
}
void bread()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tBREAD "<<"\n\n";
    cout<<"\tItem                           \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Plain Chappati             \t\t\t30/-\n";
    cout<<"\t02. Butter Chappati            \t\t\t35/-\n";
    cout<<"\t03. Plain Tandoori Roti        \t\t\t35/-\n";
    cout<<"\t04. Butter Tandoori Roti       \t\t\t40/-\n";
    cout<<"\t05. Plain Naan                 \t\t\t45/-\n";
    cout<<"\t06. Butter Naan                \t\t\t55/-\n";
    cout<<"\t07. Garlic Naan                \t\t\t65/-\n";
    cout<<"\t08. Chur Chur Naan             \t\t\t80/-\n";
    cout<<"\t09. Plain Kulcha               \t\t\t60/-\n";
    cout<<"\t10. Butter Kulcha              \t\t\t70/-\n";
    cout<<"\t11. Aloo Pyaaz Kulcha          \t\t\t80/-\n";
    cout<<"\t12. Chur Chur Kulcha           \t\t\t95/-\n";
    cout<<"\t13. Aloo Panner Kulcha         \t\t\t100/-\n";
    cout<<"\t14. Amritsari Kulcha           \t\t\t110/-\n";
    cout<<"\t15. Amritsari Panner Kulcha    \t\t\t130/-\n";
    cout<<"\t16. Stuffed Kulcha             \t\t\t110/-\n";
    cout<<"\t17. Pizza Kulcha               \t\t\t130/-\n";
    cout<<"\t18. Mushroom Kulcha            \t\t\t120/-\n";
    cout<<"\t19. Appam                      \t\t\t80/-\n";
    cout<<"\t20. Bhakhari                   \t\t\t35/-\n";
    cout<<"\t21. Roomali Roti               \t\t\t95/-\n";
    cout<<"\t22. Aloo Paratha               \t\t\t80/-\n";
    cout<<"\t23. Aloo Pyaaz Paratha         \t\t\t90/-\n";
    cout<<"\t24. Paneer Paratha             \t\t\t110/-\n";
    cout<<"\t25. Gobi Paratha               \t\t\t85/-\n";
    cout<<"\t26. Mulli Paratha              \t\t\t90/-\n";
    cout<<"\t27. Laccha Paratha             \t\t\t60/-\n";
    cout<<"\t28. Tandoori Paratha           \t\t\t70/-\n";
    cout<<"\n\n\tSelect Option ";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[166];
               fsq[166]=fsq[166]+tfsq[166];
               fsp[166]=30;
               sm(12);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[167];
               fsq[167]=fsq[167]+tfsq[167];
               fsp[167]=35;
               sm(12);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[168];
               fsq[168]=fsq[168]+tfsq[168];
               fsp[168]=35;
               sm(12);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[169];
               fsq[169]=fsq[169]+tfsq[169];
               fsp[169]=40;
               sm(12);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[170];
               fsq[170]=fsq[170]+tfsq[170];
               fsp[170]=45;
               sm(12);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[171];
               fsq[171]=fsq[171]+tfsq[171];
               fsp[171]=55;
               sm(12);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[172];
               fsq[172]=fsq[172]+tfsq[172];
               fsp[172]=65;
               sm(12);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[173];
               fsq[173]=fsq[173]+tfsq[173];
               fsp[173]=80;
               sm(12);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[174];
               fsq[174]=fsq[174]+tfsq[174];
               fsp[174]=60;
               sm(12);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[175];
               fsq[175]=fsq[175]+tfsq[175];
               fsp[175]=70;
               sm(12);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[176];
               fsq[176]=fsq[176]+tfsq[176];
               fsp[176]=80;
               sm(12);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[177];
               fsq[177]=fsq[177]+tfsq[177];
               fsp[177]=95;
               sm(12);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[178];
               fsq[178]=fsq[178]+tfsq[178];
               fsp[178]=100;
               sm(12);
               break;
        case 14:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[179];
               fsq[179]=fsq[179]+tfsq[179];
               fsp[179]=110;
               sm(12);
               break;
        case 15:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[180];
               fsq[180]=fsq[180]+tfsq[180];
               fsp[180]=130;
               sm(12);
               break;
        case 16:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[181];
               fsq[181]=fsq[181]+tfsq[181];
               fsp[181]=110;
               sm(12);
               break;
        case 17:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[182];
               fsq[182]=fsq[182]+tfsq[182];
               fsp[182]=130;
               sm(12);
               break;
        case 18:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[183];
               fsq[183]=fsq[183]+tfsq[183];
               fsp[183]=120;
               sm(12);
               break;
        case 19:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[184];
               fsq[184]=fsq[184]+tfsq[184];
               fsp[184]=80;
               sm(12);
               break;
        case 20:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[185];
               fsq[185]=fsq[185]+tfsq[185];
               fsp[185]=35;
               sm(12);
               break;
        case 21:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[186];
               fsq[186]=fsq[186]+tfsq[186];
               fsp[186]=95;
               sm(12);
               break;
        case 22:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[187];
               fsq[187]=fsq[187]+tfsq[187];
               fsp[187]=80;
               sm(12);
               break;
        case 23:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[188];
               fsq[188]=fsq[188]+tfsq[188];
               fsp[188]=90;
               sm(12);
               break;
        case 24:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[189];
               fsq[189]=fsq[189]+tfsq[189];
               fsp[189]=110;
               sm(12);
               break;
        case 25:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[190];
               fsq[190]=fsq[190]+tfsq[190];
               fsp[190]=85;
               sm(12);
               break;
        case 26:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[191];
               fsq[191]=fsq[191]+tfsq[191];
               fsp[191]=90;
               sm(12);
               break;
        case 27:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[192];
               fsq[192]=fsq[192]+tfsq[192];
               fsp[192]=60;
               sm(12);
               break;
        case 28:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[193];
               fsq[193]=fsq[193]+tfsq[193];
               fsp[193]=70;
               sm(12);
               break;
         default:cout<<"\n\n\tInvalid Option ";
                sl();
                bread();
    }
}
void deserts()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tDESSERTS "<<"\n\n";
    cout<<"\tItem                            \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Gulabjamun                  \t\t\t120/-\n";
    cout<<"\t02. Rosogulla                   \t\t\t130/-\n";
    cout<<"\t03. Rasmalai                    \t\t\t150/-\n";
    cout<<"\t04. Kheer                       \t\t\t150/-\n";
    cout<<"\t05. Gajar ka Halwa              \t\t\t140/-\n";
    cout<<"\t06. Mango Halwa                 \t\t\t180/-\n";
    cout<<"\t07. Mysore Pak                  \t\t\t140/-\n";
    cout<<"\t08. Indian Shrikhand            \t\t\t90/-\n";
    cout<<"\t09. Milk Pudding                \t\t\t100/-\n";
    cout<<"\t10. Fruit Salad                 \t\t\t120/-\n";
    cout<<"\t11. Puran Poli                  \t\t\t140/-\n";
    cout<<"\t12. Phirni                      \t\t\t150/-\n";
    cout<<"\t13. Vedmi                       \t\t\t130/-\n";
    cout<<"\t14. Kulfi                       \t\t\t80/-\n";
    cout<<"\t15. Jalebi                      \t\t\t90/-\n";
    cout<<"\t16. Rabdi                       \t\t\t110/-\n";
    cout<<"\t17. Rabdi with Jalebi           \t\t\t150/-\n";
    cout<<"\t18. Vanilla Ice-Cream           \t\t\t40/-\n";
    cout<<"\t19. Chocalate Ice-Cream         \t\t\t50/-\n";
    cout<<"\t20. Strawberry Ice-Cream        \t\t\t50/-\n";
    cout<<"\n\n\tSelect Option:";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[194];
               fsq[194]=fsq[194]+tfsq[194];
               fsp[194]=120;
               sm(13);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[195];
               fsq[195]=fsq[195]+tfsq[195];
               fsp[195]=130;
               sm(13);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[196];
               fsq[196]=fsq[196]+tfsq[196];
               fsp[196]=150;
               sm(13);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[197];
               fsq[197]=fsq[197]+tfsq[197];
               fsp[197]=150;
               sm(13);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[198];
               fsq[198]=fsq[198]+tfsq[198];
               fsp[198]=140;
               sm(13);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[199];
               fsq[199]=fsq[199]+tfsq[199];
               fsp[199]=180;
               sm(13);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[200];
               fsq[200]=fsq[200]+tfsq[200];
               fsp[200]=140;
               sm(13);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[201];
               fsq[201]=fsq[201]+tfsq[201];
               fsp[201]=90;
               sm(13);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[202];
               fsq[202]=fsq[202]+tfsq[202];
               fsp[202]=100;
               sm(13);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[203];
               fsq[203]=fsq[203]+tfsq[203];
               fsp[203]=120;
               sm(13);
               break;
         case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[204];
               fsq[204]=fsq[204]+tfsq[204];
               fsp[204]=140;
               sm(13);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[205];
               fsq[205]=fsq[205]+tfsq[205];
               fsp[205]=150;
               sm(13);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[206];
               fsq[206]=fsq[206]+tfsq[206];
               fsp[206]=130;
               sm(13);
               break;
        case 14:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[207];
               fsq[207]=fsq[207]+tfsq[207];
               fsp[207]=80;
               sm(13);
               break;
        case 15:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[208];
               fsq[208]=fsq[208]+tfsq[208];
               fsp[208]=90;
               sm(13);
               break;
        case 16:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[209];
               fsq[209]=fsq[209]+tfsq[209];
               fsp[209]=110;
               sm(13);
               break;
        case 17:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[210];
               fsq[210]=fsq[210]+tfsq[210];
               fsp[210]=150;
               sm(13);
               break;
        case 18:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[211];
               fsq[211]=fsq[211]+tfsq[211];
               fsp[211]=40;
               sm(13);
               break;
        case 19:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[212];
               fsq[212]=fsq[212]+tfsq[212];
               fsp[212]=50;
               sm(13);
               break;
        case 20:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[213];
               fsq[213]=fsq[213]+tfsq[213];
               fsp[213]=50;
               sm(13);
               break;
         default:cout<<"\n\n\tInvalid Option ";
                sl();
                deserts();
    }
}
void beverages()
{
    int a=0;
    char c;
    system("cls");
    title();
    cout<<"\n\tBEVERAGES "<<"\n\n";
    cout<<"\tItem                           \t\t\tRate"<<"\n\n\n";
    cout<<"\t01. Water Bottle               \t\t\t40/-\n";
    cout<<"\t02. Coke                       \t\t\t80/-\n";
    cout<<"\t03. Thumps Up                  \t\t\t80/-\n";
    cout<<"\t04. Pepsi                      \t\t\t80/-\n";
    cout<<"\t05. Mirinda                    \t\t\t80/-\n";
    cout<<"\t06. Fanta                      \t\t\t80/-\n";
    cout<<"\t07. Sprite                     \t\t\t80/-\n";
    cout<<"\t08. 7 Up                       \t\t\t80/-\n";
    cout<<"\t09. Mountain Dew               \t\t\t80/-\n";
    cout<<"\t10. Lemonade                   \t\t\t60/-\n";
    cout<<"\t11. Pina Colada                \t\t\t110/-\n";
    cout<<"\t12. Mint Mojito                \t\t\t120/-\n";
    cout<<"\t13. Strawbery Cocktail         \t\t\t130/-\n";
    cout<<"\t14. Kiwi Avacado               \t\t\t150/-\n";
    cout<<"\t15. Spicy Guava                \t\t\t130/-\n";
    cout<<"\t16. Fusion Mint & Strawberry   \t\t\t150/-\n";
    cout<<"\t17. Tea                        \t\t\t70/-\n";
    cout<<"\t18. Masala Tea                 \t\t\t90/-\n";
    cout<<"\t19. Black Tea                  \t\t\t100/-\n";
    cout<<"\t20. Green Tea                  \t\t\t80/-\n";
    cout<<"\t21. Ginger Tea                 \t\t\t90/-\n";
    cout<<"\t22. Lemon Tea                  \t\t\t85/-\n";
    cout<<"\t23. Honey Tea                  \t\t\t90/-\n";
    cout<<"\t24. Coffee                     \t\t\t100/-\n";
    cout<<"\t25. Black Coffee               \t\t\t110/-\n";
    cout<<"\t26. Cappichino                 \t\t\t130/-\n";
    cout<<"\t27. Brewed Coffee              \t\t\t150/-\n";
    cout<<"\t28. Frapichino                 \t\t\t140/-\n";
    cout<<"\t29. Cold Coffee                \t\t\t170/-\n";
    cout<<"\t30. Cold Coffee w/I-C          \t\t\t190/-\n";
    cout<<"\t31. Cold Coco                  \t\t\t160/-\n";
    cout<<"\t32. Cold Coco w/I-C            \t\t\t180/-\n";
    cout<<"\t33. Cold Coco Coffee           \t\t\t190/-\n";
    cout<<"\t34. Fruit Juices               \t\t\t130/-\n";
    cout<<"\t35. Thandai                    \t\t\t120/-\n";
    cout<<"\t36. Roohafza                   \t\t\t110/-\n";
    cout<<"\t37. Oreo Thick Shake           \t\t\t170/-\n";
    cout<<"\t38. Kaju Anjar Shake           \t\t\t180/-\n";
    cout<<"\t39. Banana Milkshake           \t\t\t180/-\n";
    cout<<"\t40. Guava Milkshake            \t\t\t160/-\n";
    cout<<"\n\n\tSelect Option:";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[214];
               fsq[214]=fsq[214]+tfsq[214];
               fsp[214]=40;
               sm(14);
               break;
        case 2:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[215];
               fsq[215]=fsq[215]+tfsq[215];
               fsp[215]=80;
               sm(14);
               break;
        case 3:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[216];
               fsq[216]=fsq[216]+tfsq[216];
               fsp[216]=80;
               sm(14);
               break;
        case 4:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[217];
               fsq[217]=fsq[217]+tfsq[217];
               fsp[217]=80;
               sm(14);
               break;
        case 5:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[218];
               fsq[218]=fsq[218]+tfsq[218];
               fsp[218]=80;
               sm(14);
               break;
        case 6:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[219];
               fsq[219]=fsq[219]+tfsq[219];
               fsp[219]=80;
               sm(14);
               break;
        case 7:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[220];
               fsq[220]=fsq[220]+tfsq[220];
               fsp[220]=80;
               sm(14);
               break;
        case 8:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[221];
               fsq[221]=fsq[221]+tfsq[221];
               fsp[221]=80;
               sm(14);
               break;
        case 9:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[222];
               fsq[222]=fsq[222]+tfsq[222];
               fsp[222]=80;
               sm(14);
               break;
        case 10:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[223];
               fsq[223]=fsq[223]+tfsq[223];
               fsp[223]=60;
               sm(14);
               break;
        case 11:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[224];
               fsq[224]=fsq[224]+tfsq[224];
               fsp[224]=110;
               sm(14);
               break;
        case 12:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[225];
               fsq[225]=fsq[225]+tfsq[225];
               fsp[225]=120;
               sm(14);
               break;
        case 13:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[226];
               fsq[226]=fsq[226]+tfsq[226];
               fsp[226]=130;
               sm(14);
               break;
        case 14:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[227];
               fsq[227]=fsq[227]+tfsq[227];
               fsp[227]=150;
               sm(14);
               break;
        case 15:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[228];
               fsq[228]=fsq[228]+tfsq[228];
               fsp[228]=130;
               sm(14);
               break;
        case 16:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[229];
               fsq[229]=fsq[229]+tfsq[229];
               fsp[229]=150;
               sm(14);
               break;
        case 17:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[230];
               fsq[230]=fsq[230]+tfsq[230];
               fsp[230]=70;
               sm(14);
               break;
        case 18:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[231];
               fsq[231]=fsq[231]+tfsq[231];
               fsp[231]=90;
               sm(14);
               break;
         case 19:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[232];
               fsq[232]=fsq[232]+tfsq[232];
               fsp[232]=100;
               sm(14);
               break;
        case 20:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[233];
               fsq[233]=fsq[233]+tfsq[233];
               fsp[233]=80;
               sm(14);
               break;
        case 21:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[234];
               fsq[234]=fsq[234]+tfsq[234];
               fsp[234]=90;
               sm(14);
               break;
        case 22:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[235];
               fsq[235]=fsq[235]+tfsq[235];
               fsp[235]=85;
               sm(14);
               break;
        case 23:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[236];
               fsq[236]=fsq[236]+tfsq[236];
               fsp[236]=90;
               sm(14);
               break;
        case 24:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[237];
               fsq[237]=fsq[237]+tfsq[237];
               fsp[237]=100;
               sm(14);
               break;
        case 25:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[238];
               fsq[238]=fsq[238]+tfsq[238];
               fsp[238]=110;
               sm(14);
               break;
        case 26:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[239];
               fsq[239]=fsq[239]+tfsq[239];
               fsp[239]=130;
               sm(14);
               break;
        case 27:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[240];
               fsq[240]=fsq[240]+tfsq[240];
               fsp[240]=150;
               sm(14);
               break;
        case 28:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[241];
               fsq[241]=fsq[241]+tfsq[241];
               fsp[241]=140;
               sm(14);
               break;
        case 29:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[242];
               fsq[242]=fsq[242]+tfsq[242];
               fsp[242]=170;
               sm(14);
               break;
        case 30:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[243];
               fsq[243]=fsq[243]+tfsq[243];
               fsp[243]=190;
               sm(14);
               break;
        case 31:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[244];
               fsq[244]=fsq[244]+tfsq[244];
               fsp[244]=160;
               sm(14);
               break;
        case 32:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[245];
               fsq[245]=fsq[245]+tfsq[245];
               fsp[245]=180;
               sm(14);
               break;
        case 33:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[246];
               fsq[246]=fsq[246]+tfsq[246];
               fsp[246]=190;
               sm(14);
               break;
        case 34:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[247];
               fsq[247]=fsq[247]+tfsq[247];
               fsp[247]=130;
               sm(14);
               break;
        case 35:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[248];
               fsq[248]=fsq[248]+tfsq[248];
               fsp[248]=120;
               sm(14);
               break;
        case 36:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[249];
               fsq[249]=fsq[249]+tfsq[249];
               fsp[249]=110;
               sm(14);
               break;
        case 37:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[250];
               fsq[250]=fsq[250]+tfsq[250];
               fsp[250]=170;
               sm(14);
               break;
        case 38:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[251];
               fsq[251]=fsq[251]+tfsq[251];
               fsp[251]=180;
               sm(14);
               break;
        case 39:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[252];
               fsq[252]=fsq[252]+tfsq[252];
               fsp[252]=180;
               sm(14);
               break;
        case 40:cout<<"\n\tEnter Quantity : ";
               cin>>tfsq[253];
               fsq[253]=fsq[253]+tfsq[253];
               fsp[253]=160;
               sm(14);
               break;
        default:cout<<"\n\n\tInvalid Option ";
                sl();
                beverages();
    }
}
};
class option : public foodtype
{
public:
void srt()
{
    char a[23]="Welcome To JN Marriott";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int b=0; b<120; b++)
    {
        fl();
        cout<<"*";
    }
    cout<<"\n\t\t\t\t\t\t   ";
    for(int c=0; c<23; c++)
    {
        ml();
        cout<<a[c];
    }
    cout<<"\n\n";
    for(int d=0; d<120; d++)
    {
        fl();
        cout<<"*";
    }
    for(int e=0; e<1000000000; e++);
    system("cls");
    psd();
}
  void psd()
{
    psd:
    system("cls");
    int t=0,i;
    char a[10],b[]="123";
    for(i=0; i<60; i++)
    cout<<"/\\/\\";
    cout<<"\n\t\t\t\t\t\t\n"<<endl;
    cout<<"\t\t\t\t\t\t    <> SIGN-IN <>"<<endl;
    cout<<"\t\t\t\t\t\t"<<endl;
    cout<<"\n";
    for(i=0; i<30; i++)
    cout<<"\\/\\/";
    for(i=0; i<30; i++)
    cout<<"----";
    for(i=0; i<30; i++)
    cout<<"/\\/\\";
    cout<<"\n\n\n\t\t\t\t\t\t  UserName :   "<<"Admin"<<endl;
    cout<<"\n\t\t\t\t\t\t  Password :   ";
    cin>>a;
    for(i=0; b[i]!='\0'; i++)
    {
        if(b[i]!=a[i])
            t=1;
    }
    if(t==1)
    {
        cout<<"\n\n\n";
        for(i=0; i<120; i++)
        cout<<"-";
        cout<<"\n\t\t\t\t       Sorry Your Entered Password Is Incorrect\n\t\t\t\t\t         --->Try Again<---"<<endl;
        for(int j=0; j<2000000000; j++);
        goto psd;
    }
    if(t==0)
    {
        system("cls");
        opt();
    }
}
void pi()//function for personal info
{
        cout<<"\tEnter Your Name:- ";
        cin.ignore();
        gets(nm);
        cout<<"\tEnter Your Mobile No.:- ";
        cin>>mn;
}
void opt()//option for dine / take out
{
    st=0;
    for(int i=0;i<255;i++)
    {
        tfsq[i]=0;
        fsq[i]=0;
    }
    a:
    system("cls");
    title();
    cout<<"\t"<<endl<<endl;
    cout<<"\t1. Dine In "<<endl;
    cout<<"\t2. Take Out "<<endl;
    cout<<"\t3. Bill History "<<endl<<endl;
    cout<<"\tEnter Option: ";
    cin>>dito;
    switch (dito)
    {
        case 1  : di();
                  break;
        case 2  : to();
                  break;
        case 3  : sb();
                  break;
        default :cout<<"\n\n\n\t'Invalid Input'";
                 sl();
                 goto a;
                 break;
    }
}
void di()
{
    system("cls");
    title();
    cout<<"\n\tDine In \n"<<endl;
    tbn = randnum(30);
    cout<<"\tTable No.: "<<tbn<<endl;
    pi();
    system("cls");
    ft();
}
void to()
{
    system("cls");
    title();
    cout<<"\n\tTake Out \n"<<endl;
    cout<<"\tToken No. : "<<tn<<endl;
    btn=tn;
    tn++;
    pi();
    system("cls");
    ft();
}
}a;
int main()
{
    a.srt();
    return 0;
}
void gb()
{
    system("cls");
    for(int n=0; n<4; n++)
    {
         cout<<"\n\n\n\n\n\n\n";
         cout<<"\n\n\t\t\t\tGenerating your Bill";
         for(int l=0; l<4; l++)
         {
            ml();
            cout<<".";
         }
        system("cls");
    }
    bill();
}
int randnum(int a)
{
    int random;
    srand(time(NULL));
    random=rand()%a;
    return random;
}
void title()
{
    cout<<"\n";
    cout<<"\t\t\t\t\t\t      ------------"<<endl;
    cout<<"\t\t\t\t\t\t     / JN Marriott /"<<endl;
    cout<<"\t\t\t\t\t\t      ------------"<<endl<<endl;
}
void fl()
{
    for(int a=0; a<10000000; a++);
}
void ml()
{
    for(int b=0; b<100000000; b++);
}
void sl()
{
    for(int i=0; i<1000000000; i++);
}
void smily()
{
    cout<<"\t\t\t\t\t\t.............."<<endl;
    cout<<"\t\t\t\t\t\t..          .."<<endl;
    cout<<"\t\t\t\t\t\t..  *    *  .."<<endl;
    cout<<"\t\t\t\t\t\t..    *     .."<<endl;
    cout<<"\t\t\t\t\t\t..  :...:   .."<<endl;
    cout<<"\t\t\t\t\t\t..          .."<<endl;
    cout<<"\t\t\t\t\t\t.............."<<endl;
}
void fb()
{
    if(dito==1)
        feedback();
    if(dito==2)
    {
       gb();
    }

}
void feedback()
{
    system("cls");
    char d[50];
    int e,f,g,h,i,j;
    cout<<"\n";
    for(int a=0; a<54; a++)
        cout<<"*";
    cout<<"Feedback Form";
    for(int a=0; a<53; a++)
        cout<<"*";
    cout<<"\n\tName: ";
    cout<<nm;
    cout<<"\n\tPhone Number: ";
    cout<<mn;
    cout<<"\n\tEmail: ";
    cin>>d;
    cout<<"\n\n\t**Rate Out Of 10**";
    cout<<"\n\n\tAmbience       : ";
    cin>>e;
    cout<<"\tStaff          : ";
    cin>>f;
    cout<<"\tCleanliness    : ";
    cin>>g;
    cout<<"\tFood           : ";
    cin>>h;
    cout<<"\tValue for Money: ";
    cin>>i;
    cout<<"\tOverall        : ";
    cin>>j;
    system("cls");
    for(int n=0; n<6; n++)
    {
        smily();
         cout<<"\n\n\n\t\t\t\t\tThanks for your Feedback.\n      \t\t\t\t\t\tYour Feedback is valuable for us.";
         cout<<"\n";
         cout<<"            \t\t\t\t\t\tWe will look after it";
         for(int l=0; l<4; l++)
         {
            ml();
            cout<<".";
         }
         system("cls");
    }

    gb();
}
void time()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    d=(timePtr->tm_mday);
    mi=(timePtr->tm_mon)+1;
    y=(timePtr->tm_year)+1900;
    h=(timePtr->tm_hour);
    m=(timePtr->tm_min);
    s=(timePtr->tm_sec);
}
void bfn()
{
    time();
    fstream a;
    a.open("temp.txt", ios::out);
    a<<bn<<d<<mi<<y;
    a<<".txt";
    a.close();
    a.open("temp.txt", ios::in);
    a.get(fn,20);
    a.close();
}
void bill()
{
    system("cls");
    fstream o;
    bn++;
    bfn();
    o.open(fn,ios::out);
    int i,k,b,c=0,v;
    cout<<"\n\t\t\t\t\t\t\tJN Marriott\n";
    cout<<"\t\t\t\t\t  Asset Area 4-Hospitality District Delhi\n\t\t\t\t\t\t   Aerocity,Delhi-110037\n";
    cout<<"\n\t\tContact:011-4521-2121\t\t\t\t\t\tGSTIN:24AAAAK8694F2ZF\n\n";
    o<<"\n\t\t\t\t\t\t\tJN Marriott\n";
    o<<"\t\t\t\t\t  Asset Area 4-Hospitality District Delhi\n\t\t\t\t\t\t   Aerocity,Delhi-110037\n";
    o<<"\n\t\tContact:011-4521-2121\t\t\t\t\t\tGSTIN:24AAAAK8694F2ZF\n\n";
    for(int i=0; i<120; i++)
    {
        cout<<"-";
        o<<"-";
    }
    cout<<"\t\t\t\t\t\t\t\t";
    o<<"\n\t\t\t\t\t\t\t";
    if(dito==1)
    {
        cout<<"Dine In\n";
        o<<"Dine In\n";
    }
    else
    {
        cout<<"Take Out\n";
        o<<"Take Out\n";
    }
    for(int i=0; i<120; i++)
    {
         cout<<"-";
         o<<"-";
    }
    if(dito==1)
    {
        cout<<"\n\t\tTable No.:" <<tbn;
        o<<"\n\t\tTable No.:" <<tbn;
    }
    if(dito==2)
    {
        cout<<"\n\t\tToken No.:" <<btn;
        o<<"\n\t\tToken No.:" <<btn;
    }
    cout<<"\t\t\t\t\t\t\tBill No.:"<<bn;
    cout<<"\n\t\tDate:"<<d<<"/"<<mi<<"/"<<y;
    cout<<"\t\t\t\t\t\t\tGuest:"<<nm;
    cout<<"\n\t\tTime:"<<h<<":"<<m<<":"<<s;
    cout<<"\t\t\t\t\t\t\tGuest's Contact:"<<mn<<endl;
    o<<"\t\t\t\t\t\t\tBill No.:"<<bn;
    o<<"\n\t\tDate:"<<d<<"/"<<mi<<"/"<<y;
    o<<"\t\t\t\t\t\t\tGuest:"<<nm;
    o<<"\n\t\tTime:"<<h<<":"<<m<<":"<<s;
    o<<"\t\t\t\t\t\t\tGuest's Contact:"<<mn<<endl;
    for(int i=0; i<120; i++)
    {
        cout<<"-";
        o<<"-";
    }
    cout<<"\n\n\t\tS.R. No.\tItem\t\t\t\t\t    Quantity\tRate\tAmount\n\n";
    o<<"\n\n\t\tS.R. No.\tItem\t\t\t\t\t    Quantity\tRate\tAmount\n\n";
    for(int i=0; i<120; i++)
        {
            cout<<"-";
            o<<"-";
        }
    for(i=0; i<255; i++)
    {
        b=0;
            if(fsq[i]>0)
            {
                cout<<"\n\t\t";
                o<<"\n\t\t";
                c++;
                cout<<c<<"\t\t";
                o<<c<<"\t\t";
                b=strlen(fs[i]);
                cout<<fs[i];
                o<<fs[i];
                for(k=b; k<40; k++)
                {
                    cout<<" ";
                    o<<" ";
                }
                cout<<"      "<<fsq[i];
                o<<"      "<<fsq[i];
                if(fsq[i]<10)
                {
                    cout<<"          ";
                    o<<"          ";
                }
                else if(fsq[i]<100)
                {
                    cout<<"         ";
                    o<<"         ";
                }
                else
                {
                    cout<<"        ";
                    o<<"        ";
                }
                cout<<fsp[i]<<"\t "<<fsp[i]*fsq[i];
                o<<fsp[i]<<"\t "<<fsp[i]*fsq[i];
                st=fsp[i]*fsq[i]+st;
            }
    }
    cout<<"\n";
    o<<"\n";
    for(int i=0; i<120; i++)
       {
           cout<<"-";
           o<<"-";
       }
    int cg=(2.5*st)/100,sg=(2.5*st)/100;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tSub Total :      "<<st;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tCGST(2.5%):      "<<cg<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\tSGST(2.5%):      "<<sg<<endl;
    o<<"\n\t\t\t\t\t\t\t\t\t\tSub Total :      "<<st;
    o<<"\n\t\t\t\t\t\t\t\t\t\tCGST(2.5%):      "<<cg<<endl;
    o<<"\t\t\t\t\t\t\t\t\t\tSGST(2.5%):      "<<sg<<endl;
    for(int i=0; i<120; i++)
    {
        cout<<"-";
        o<<"-";
    }
    ta=st+cg+sg;
    cout<<"\t\t\t\t\t\t\t\t\t\t\tTotal Amount :   "<<ta<<endl;
    o<<"\n\t\t\t\t\t\t\t\t\t\tTotal Amount :   "<<ta<<endl;
    for(int i=0; i<120; i++)
    {
            cout<<"-";
            o<<"-";
    }
    cout<<"\n\n\t\t\tThis is a Computer Generated Invoice and Hence No Signature Required\n";
    cout<<"\n\t\t\t\t\t\t**Thank You.Visit Again**\n";
    o<<"\n\n\t\t\tThis is a Computer Generated Invoice and Hence No Signature Required\n";
    o<<"\n\t\t\t\t\t\t**Thank You.Visit Again**\n";
    for(int i=0; i<120; i++)
    {
        cout<<"-";
        o<<"-";
    }
    o.close();
    cout<<"\n\n\t\tSelect Payment Mode: ";
    cout<<"\n\n\t\t1. CC(Credit Card)";
    cout<<"\n\t\t2. DC(Debit Card)";
    cout<<"\n\t\t3. Cash";
    cout<<"\n\n\t\tEnter your choice: ";
    cin>>v;
    payment(v);
}
void sb()
{
    system("cls");
    title();
    cout<<"\n\tBill History \n"<<endl;
    char a[1000],bn[5],date[10],temp[5]={".txt"},v;
    fstream o;
    cout<<"\tEnter Bill No: ";
    cin>>bn;
    cout<<"\tEnter Date(Eg.\"19102019\"): ";
    cin>>date;
    strcat(bn,date);
    strcat(bn,temp);
    o.open(bn,ios::in);
    if(!o)
    {
        cout<<"\n\n\tBill Not Found";
    }
    else
    {
      system("cls");
      for(int i=0; i<30; i++)
      {
        o.getline(a,1000);
        cout<<"\n"<<a;
      }
    }
    o.close();
    cout<<"\n\n\t\tFor Next Order:q";
    cout<<"\n\n\t\tFor Exiting:e";
    cout<<"\n\n\n\tEnter Your Choice :";
    cin>>v;
    switch(v)
    {
        case 'q':option a;
                 a.opt();
                 break;
        case 'e':system("cls");
                 break;
    }
}
void payment(int a)
{
    int ra,ar;
    switch(a)
    {
        case 1:system("cls");
               title();
               cout<<"\n\n\tPAYMENT";
               cout<<"\n\n\n\tOpted payment mode : CC";
               cout<<"\n\tAmount to be paid  : "<<ta;
               sl();
               ml();
               break;
        case 2:system("cls");
               title();
               cout<<"\n\n\tPAYMENT";
               cout<<"\n\n\n\tOpted payment mode : DC";
               cout<<"\n\tAmount to be paid  : "<<ta;
               sl();
               ml();
               break;
        case 3:system("cls");
               title();
               cout<<"\n\n\tPAYMENT";
               cout<<"\n\n\n\tOpted payment mode      : Cash";
               cout<<"\n\tAmount to be paid       : "<<ta;
               cout<<"\n\tAmount Received         : ";
               cin>>ar;
               ra=ar-ta;
               cout<<"\tAmount To Be Returned   : "<<ra;
               sl();
               ml();
               break;
        default:cout<<"\n\t\tInvalid Input!!";
                sl();
                system("cls");
                bill();
    }
    pr(a);
}
void pr(int a)
{
    system("cls");
    int d;
    char e,b,c[7][30]={" HDFC"," IDFC"," AXIS","ICICI","  SBI","UNION","  BOB"};
    if(a!=3)
    {
         time();
         d=randnum(7);
         for(int n=0; n<4; n++)
         {
         cout<<"\n\n\n\n\n\n\n";
         cout<<"\n\n\t\t\t\tPayment Processing";
         for(int l=0; l<3; l++)
         {
            ml();
            cout<<".";
         }
         system("cls");
         }
         cout<<"\t\t\t\t\t\t    Payment Receipt\n\n";
         cout<<"\t\t\t\t\t******************************************\n";
         cout<<"\t\t\t\t\t\t       "<<c[d]<<" Bank\n";
         cout<<"\t\t\t\t\t******************************************\n";
         cout<<"\n\t\t\t\t\t"<<::d<<"\\"<<mi<<"\\"<<y<<"\t\t      "<<h<<":"<<m<<":"<<s;
         cout<<"\n\n\t\t\t\t\tCard No. \t\t  ************"<<randnum(10)<<randnum(9)<<randnum(8)<<randnum(7)<<"\n\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------\n";
         cout<<"\t\t\t\t\tAmount"<<"\t\t\t\t      "<<ta<<"\n";
         cout<<"\t\t\t\t\t-------------------------------------------\n";
         cout<<"\n\n\n\n\n\n\n\n\t\t\t\tPress Enter to continue...";
         cin.ignore();
         cin.get(e);
         system("cls");
    }
    cout<<"\n\n\t\tFor Next Order:q";
    cout<<"\n\n\t\tFor Exiting:e";
    cout<<"\n\n\n\t\tEnter Your Choice :";
    cin>>b;
    switch(b)
    {
        case 'q':option a;
                 a.opt();
                 break;
        case 'e':system("cls");
                 break;
    }
}
