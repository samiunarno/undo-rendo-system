#include <iostream>
#include <stack>
using namespace std;
void display(stack<string>x)
{

    while(!x.empty()){
        cout<<x.top()<<" ";
        x.pop();
    }
    cout<<"\n";
}

int main()
{
    stack<string> newly_added;
    stack<string> recently_deleted;
    while(1)
        {

        cout<<"Enter a command: ";
        string command;
        cin>>command;

        newly_added.push(command);
        again :

        cout<<"Press 1: Undo\nPress 2: Redo";
        cout<<"\nPress 3: Next command\nPress 4: Exit ";
        cout<<"\nChoose an option: ";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            newly_added.pop();
            recently_deleted.push(command);
            cout<<"Current Command List from newest to oldest : ";
            display(newly_added);
            goto again;
        }
        if(choice==2)
        {
            if(!recently_deleted.empty())
            {
                newly_added.push(recently_deleted.top());
                recently_deleted.pop();

            }
            cout<<"Current Command List from newest to oldest : ";

            display(newly_added);
            goto again;
        }
        if(choice==3)
        {
            continue;
        }
        if(choice==4)
        {
            cout<<"Current Command List from newest to oldest : ";
            display(newly_added);
            exit(1);
        }
    }
}
