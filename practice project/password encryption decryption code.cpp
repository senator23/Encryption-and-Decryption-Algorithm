#include<iostream>
#include<cstring>
using namespace std;

void decodePass(char* arr,string* cracker,int length){
    string answer,temp;
    int stringLength,i=0,value,ascii;
    while(i<length){
        ascii=(int)arr[i];
        temp=cracker[i];
        stringLength=temp.length();
        int j=0;
        while(j<stringLength){
            if((int)temp.at(j)==46){
                j++;
                value=(int)temp.at(j)-48;
                if(value==0){
                    ascii--;
                }else{
                    value*=2;
                    ascii-=value;
                }
            }
            else{
                value=(int)temp.at(j)-48;
                if(value==0){
                    ascii++;
                }else{
                    value*=2;
                    ascii+=value;
                }
            }
            j++;
        }
        answer.push_back((char)ascii);
        i++;
    }
    cout<<"Recovered password: "<<answer<<endl;
}


void crackPassword(string pass){
    int length=pass.length();
    //cout<<"pass.length is:"<<pass.length()<<endl;
    int i=0;
    char result[length];
    string loops[length];
    string crack;
    int temp,spare;
    while(i<length){
        temp=(int) pass.at(i);
        //cout<<"temp value"<<temp<<endl;(RETURN ASCII VALUE OF EACH CHARACTER IN STRING)
        //cout<<"string value"x<<pass.at(i)<<endl;(EACH CHARATER OF STRING)
        crack.clear();
        while((temp>=65 && temp<=90)||(temp>=97 && temp<=122)||(temp>=48 && temp<=57)){
            if(temp%10==0){
                crack+=to_string(0);
                temp--;
            }
            spare=(temp%10);
            crack+=to_string(spare);
            spare*=2;
            temp-=spare;
        }
        while(temp<33){
            crack+='.'+ to_string(temp%10);
            temp+=temp%10*2;
        }
        result[i]=temp;
        loops[i]=crack;
        i++;
    }
    i=0;
    cout<<"Value you entered is : "<<pass<<endl<<"Password generated is : ";
    while(i<length){
        cout<<result[i];
        i++;
    }
    cout<<endl;
    decodePass(result,loops,length);
}

int main(){
    string value="null";
    //crackPassword("ABCDEFGHIJKLM&672_+@#NOPQRSTUVWXYZabcdefghijklmnopqrstu0123vw456xy789(z)");
    while(value!="quit"){
        cout<<"Enter Password:"<<endl;
        cin>>value;
        crackPassword(value);
    }
    return 0;
}
