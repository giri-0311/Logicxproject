#include<iostream>
using namespace std;
#include<string>

///This function checks if sequent is a premise or not 
///
///This function return true if the sequent is a valid premise else returns false
///@param rule the part of sequent which indicates the specified rule 
bool premise(string rule)
{
    bool q = ((rule=="p")||(rule=="P"));
    return q;
}
///This function checks if sequent has used the valid rule 'and introduction ' or not 
///
///This function return true if the sequent is a valid premise else returns false
///@param rule the part of sequent which indicates the specified rule
///@param expression the part of the sequent which contains expression.
///@param l1 the part of the sequent which points towards the previous sequent lines which are required by the rule
///@param l2 the part of the sequent which points towards the previous sequent lines which are required by the rule
bool andintro(string rule, string expression, string l1,string l2)
{
    bool q = (rule=="^i" && (expression[l1.length()]=='^') &&(expression.compare(0,l1.length(),l1)==0)&&(expression.compare(l1.length()+1,l2.length(),l2)==0));
    return q;
}
///This function checks if sequent has used the valid rule 'and elimination 1' or not 
///
///This function return true if the sequent is a valid premise else returns false
bool andeli1(string rule, string expression, string l1,string l2)
{
    bool q = (rule=="^e1" && l1[expression.length()]=='^' && (l1.compare(0,expression.length(),expression)==0));

    return q;
}
///This function checks if sequent has used the valid rule 'and elimination 2' or not 
///
///This function return true if the sequent is a valid premise else returns false
bool andeli2(string rule, string expression, string l1,string l2)
{
    bool q = (rule=="^e2" && l1[l1.length()-expression.length()-1]=='^' && (l1.compare(l1.length()-expression.length(),expression.length(),expression)==0));

    return q;
}
///This function checks if sequent has used the valid rule 'or introduction 1' or not 
///
///This function return true if the sequent is a valid premise else returns false
bool orintro1(string rule, string expression, string l1,string l2)
{
    bool q = (rule=="vi1" && expression[l1.length()]=='v' && (expression.compare(0,l1.length(),l1)==0));

    return q;
}
///This function checks if sequent has used the valid rule 'or introduction 2' or not 
///
///This function return true if the sequent is a valid premise else returns false
bool orintro2(string rule, string expression, string l1,string l2)
{
    bool q = (rule=="vi2" && expression[expression.length()-l1.length()-1]=='v'&& (expression.compare(expression.length()-l1.length(),l1.length(),l1)==0));

    return q;
}
///This function checks if sequent has used the valid rule 'inplecation elimination' or not 
///
///This function return true if the sequent is a valid premise else returns false
bool inpleli(string rule, string expression, string l1,string l2)
{
    bool q = (rule==">e" && (l1[l2.length()]=='>')&& l1.compare(0,l2.length(),l2)==0 &&l1.compare(l2.length()+1,expression.length(),expression)==0);

    return q;
}
///This function checks if sequent has used the valid rule 'modus tollens' or not 
///
///This function return true if the sequent is a valid premise else returns false
bool mt(string rule, string expression, string l1,string l2,string r)
{
    bool q = (rule=="MT" && (l1.compare(0,r.length(),r)==0)&& l1[r.length()]=='>' &&l1.compare(r.length()+1,l2.length()-1,l2.substr(1))==0 );

    return q;
}
///@param n this stores the number of lines of proof
///@param flag this stores whether the entire proof is valid (with value 1) or invalid (with value 0)
///@param c this store the number of forward slashes encountered in every line of the proof
int main()
{
    string s;
    int n; 
    cout<<"please enter the number of lines of proof\n";
    cin>>n;
    int flag=1;
    string a[n];
    for(int i=0;i<n;i++)
    {
        if(i==n)
        {
            flag=1;     
        }
        string expression="";
        string rule="";
        int line1=1;
        int line2=1;
        int c=0;
        cin>>s;
        for(int j=0;s[j]!='\0';j++)
        {
            if(s[j]=='/')
            {
                c++;
            }
            else if(s[j]=='('||s[j]==')'||s[j]==' ')
            {
                continue;
            }
            else
            {
            if(c==0)
            {
                expression.append(s,j,1);
            }
            if(c==1)
            {
                rule.append(s,j,1);
            }
            if(c==2)
            {
                line1=s[j]-'0';
            }
            if(c==3)
            {
                line2=s[j]-'0';
            }
            }
        }
            a[i]=expression;
            string l1=a[line1-1];
            string l2=a[line2-1];
            string r=expression.substr(1);
            if(premise(rule)){}
          else  if(andintro(rule,  expression,  l1, l2)){}
          else  if(andeli1( rule,  expression,  l1, l2)){}
          else   if(andeli2( rule,  expression,  l1, l2)){}
          else  if(orintro1( rule,  expression,  l1, l2)){}
          else if(orintro2( rule,  expression,  l1, l2)){}
          else  if(inpleli( rule,  expression,  l1, l2)){}
          else if(mt( rule,  expression,  l1, l2, r)){}
          else{flag=0;}
        }
    
    if(flag==0)
    cout<<"invalid\n";
    else
    cout<<"valid\n";
}
