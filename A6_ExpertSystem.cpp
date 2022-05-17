#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"\t\t_____Welcome to the live virtual covid predictor_____"<<endl;
    cout<<endl;

    vector<string> ques01={
        "What is the body temperature?(float value in Fareheit)",
        "What is the oxygen level?(integer value)(0-100)",
        "How many covid vaccines are taken?(0,1,2)"    
    };
    vector<string> ques02={
        "Does the patient have fever?(yes/no)",
        "Does the patient have headache?(yes/no)",
        "Can the patient detect smell?(yes/no)",
        "Can the patient recognize the taste?(yes/no)",
        "Does the patient have cough?(Yes/no)",
        "Did the patient come in contact with any covid positive patient?",
        "Is there difficulty in breathing?(Yes/no)"
    };
    int severity=0;
    int suspicion=0;
    int temp=0;
    int oxylevel=0;

    for(int i=0;i<ques02.size();i++){
        string a;
        cout<<ques02[i]<<endl;
        cin>>a;
        if(i==2 and i==3){
            if(a=="no"){
                suspicion++;
            }
            
        }
        else{
            if(a=="yes"){
                suspicion++;
            }
        }
    }
    for(int i=0;i<ques01.size();i++){
        if(i==0){
            float fever;
            cout<<ques01[i]<<endl;
            cin>>fever;
            if(fever>=101){
                severity+=2;
                suspicion++;
                temp=1;
            }
            else if(fever>99){
                severity++;
                
            }                
        }
        if(i==1){
            int oxy;
            cout<<ques01[i]<<endl;
            cin>>oxy;
            if(oxy<=80){
                severity+=2;
                suspicion++;
                oxylevel=1;
            }
            else if(oxy<=94){
                severity++;
            }
        }
        if(i==2){
            int doses;
            cout<<ques01[2]<<endl;
            cin>>doses;
            if(doses==0){
                severity+=2;
                suspicion++;
            }
            else if(doses==1){
                severity++;
                
            }
            
        }
    }
    if(suspicion>3){
        cout<<"You are probably covid infected"<<endl;
        if(severity<3){
            cout<<"It looks like the symptoms are mild \n\t Home Quarantine"<<endl;
        }
        else if(severity>=3 and severity<6){
            cout<<"The patient can get an admission in the general ward\n"<<endl;
        }
        else{
            cout<<"The patient looks critical"<<endl;
        }
    }
    else{
        cout<<"\n\t It looks like the patient is not covid positive\n"<<endl;
    }
    if(oxylevel){
        cout<<"\n\t Keep monitoring the patient's oxygen level\n"<<endl;
    }
    if(temp){
        cout<<"\n\t Keep monitoring the patient's body temperature\n"<<endl;
    }
    cout<<"\n\t Thank You!!!"<<endl;


}