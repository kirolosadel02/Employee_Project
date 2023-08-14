#include <bits/stdc++.h>
using namespace std;

struct Employees{
    string name;
    float age=0;
    double salary=0;
    char gender=0;
};
vector<Employees>employee;

void home(){
    cout<<"Enter your choice from:"<<'\n';
    cout<<"1) Add new employee"<<'\n';
    cout<<"2) Print all Employees"<<'\n';
    cout<<"3) Delete by age"<<'\n';
    cout<<"4) Update salary by name"<<'\n';
}
void AddNewEmployee(){
    string name;
    float age;
    double salary;
    char gender;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter gender (M/F): ";
    cin >> gender;
    employee.emplace_back() = {name, age, salary, gender};
    cout<<"Successfully added"<<'\n';
    cout<<"====================="<<'\n';
}
void PrintAllEmployees(){
    int deleted=0;
    for (auto & i : employee) {
        if(i.age != -1)
            cout<<i.name<<' '<<i.age<<' '<<i.salary<<' '<<i.gender<<'\n';
        else
            deleted++;
    }
    if(deleted == employee.size())
        cout<<"No Employees"<<'\n';
    cout<<"====================="<<'\n';

}
void DeleteByAge(float from,float to){
    for (auto & i : employee) {
        if(i.age >= from && i.age <=to){
            i.age = -1;
        }
    }
}
void UpdateSalaryByName(const string& name,double salary){
    for (auto & i : employee) {
        if(i.name == name)
            i.salary = salary;
    }
}
void choice(int WhatToDo){
    if(WhatToDo == 1){
        AddNewEmployee();
    }
    else if(WhatToDo == 2){
        PrintAllEmployees();
    }
    else if(WhatToDo == 3){
        float start,end;
        cout<<"Enter start & end age: ";
        cin >> start >> end;
        DeleteByAge(start,end);
    }
    else if(WhatToDo == 4){
        cout<<"Enter name and new salary: ";
        string name;
        double salary;
        cin>>name>>salary;
        UpdateSalaryByName(name,salary);
    }
}
int main(){
    while(true) {
        home();
        int WhatToDo;
        cin >> WhatToDo;
        if(WhatToDo<1 || WhatToDo>4){
            cout<<"Thank You!";
            break;
        }
        choice(WhatToDo);
    }
}