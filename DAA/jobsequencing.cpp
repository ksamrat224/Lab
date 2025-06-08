#include<iostream>
using namespace std;
#define N 5
struct Job {
    string ID;
    int deadLine;
    int profit;
}; 
void Print(struct Job J[]) {
    for (int i = 0; i < N; i++) {
        cout << "Job ID: " << J[i].ID 
             << ", Deadline: " << J[i].deadLine 
             << ", Profit: " << J[i].profit << endl;
    }
}
void Sort(struct Job J[]) {
   int i, j;
    struct Job temp;
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(J[j].profit<J[j+1].profit){
                temp=J[j];
                J[j]=J[j+1];
                J[j+1]=temp;
            }
        }
    }
}
int scheduleJobs(struct Job J[], int D) {
    int result[N]; // To store the result (job IDs)
    bool slot[N]; // To keep track of free time slots
    for (int i = 0; i < N; i++) {
        slot[i] = false;
    }
    int totalProfit = 0;
    for (int i = 0; i < N; i++) {
        for (int j = min(D, J[i].deadLine) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                slot[j] = true;
                result[j] = i; // Store the job ID
                totalProfit += J[i].profit;
                break;
            }
        }
    }
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < D; i++) {
        if (slot[i]) {
            cout << J[result[i]].ID << " ";
        }
    }
    return totalProfit;
}



int main () {
int D;
struct Job J[N] = {{"j1", 2, 18}, {"j2", 1, 10}, {"j3", 3, 40}, {"j4", 3, 28}, {"j5", 2, 20}};
cout<<"List of available jobs:\n";
Print(J);
Sort(J); //use bubble sort to sort the jobs based on profit in descending order
cout<<"\nSorted list of jobs based on profit:\n";
Print(J);
cout<<"\nEnter the deadline for the jobs: ";
cin>>D; //input the deadline
 int totalProfit = scheduleJobs(J, D); //call the function to schedule jobs and calculate total profit
cout<<endl<<endl<<"Total Generated Profit:"<<totalProfit<<endl;
return 0;

};
