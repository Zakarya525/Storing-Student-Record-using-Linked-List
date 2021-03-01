#include <iostream>
#include <string.h>
using namespace::std;
static int count = 0;
class Student{
	public:
		string regNo;
		int age;
		float cgpa;
		int currSem;
		Student* next;
	
		Student(string reg_no, int student_age, float student_gpa, int current_sem){
		
			regNo = reg_no;
			age = student_age;
			cgpa = student_gpa;
			currSem = current_sem;
			next = NULL;
		
		}
		void display(){
			cout<<endl<<"Registration No: "<<regNo<<"\nAGe = "<<age<<"\nCGPA = "<<cgpa<<"\nCurrent Semester: "<<currSem<<endl<<endl;
		}	
	};


class Linkedlist{
	public:
	Student* head;
	
		Linkedlist(){
			head = NULL;
		}
		
		void insertAtHead(Student* currentStudent){
			if(head == NULL){
				head = currentStudent;
			}
			else{
				currentStudent->next = head;
				head = currentStudent;
			}
		}
		
		void traverseData(){
			if(head == NULL){
				cout<<"There is no data of students"<<endl;
			}
			else{
			Student* current = head;
			current->display();
			while(current->next != NULL){
				current = current->next;
				current->display();
			}
			}
		}
			
		void removeFirst(){
			if(head == NULL){
				cout<<"List is empty";
			}
			else{
				Student* current = head;
				head = head->next;
				delete current;
				cout<<"\nFirst student data has been deleted"<<endl;
			}
			
			}
			
		void bubbleSort(){
			Student* last = NULL;
			while(last != head){
				Student* current = head;
				Student* temp;
				while(current->next != last){
					if(current->cgpa > current->next->cgpa){
						Student* target = current->next;
						current->next = target->next;
						target->next = current;
						
						if(current == head){
							head = target;
							current = target;
						}
						else{
							current = target;
							temp->next = current;
						}
					}
					temp = current;
					current = current->next;
					}
				last = current;
				}		
	}
			
		
		
			
		Student* search(string regno){
			Student* current = head;
			while(current->next != NULL and current->regNo != regno){
				current = current->next;
			}
			if(current->regNo != regno){
				return 0;
			}
			else{
				return current;
			}
		}
		
		Student* rec_reverse(Student* student){
			if(student == NULL)
				return NULL;
				
			if(head->next == NULL){
				head = student;
				return head;
			}
			else{
				Student* student1 = rec_reverse(head->next);
				student1->next = head;
				head->next = NULL;
				return head;
				
			}
		}
		
		
		Student* rec(Student* head){
			if(head == NULL){
				return NULL;
			}
			else{
				rec(head->next);
				cout<<head->regNo<<endl;
			}
		}
};

int main(int argc, char** argv) {
	
	Linkedlist* student = new Linkedlist();
	string regNo;
	int age;
	float cgpa;
	int currSem;
	
	
		student->insertAtHead(new Student("19MDSWE050", 20, 3.43, 3));
		student->insertAtHead(new Student("19MDSWE051", 20, 3.3, 3));
		student->insertAtHead(new Student("19MDSWE052", 22, 3.76, 3));
		student->insertAtHead(new Student("19MDSWE053", 24, 3.29, 3));
		student->insertAtHead(new Student("19MDSWE054", 19, 3.75, 3));
		student->insertAtHead(new Student("19MDSWE055", 22, 3.22, 3));
		student->insertAtHead(new Student("19MDSWE056", 20, 1.89, 3));
		student->insertAtHead(new Student("19MDSWE057", 22, 2.89, 3));
		student->insertAtHead(new Student("19MDSWE058", 23, 3.51, 3));
		student->insertAtHead(new Student("19MDSWE059", 20, 3.5, 3));
	
	
	cout<<"\n\nThe all students before sort data are: ";
	student->traverseData();
	
	student->bubbleSort();
	
	cout<<"\n\nThe all students after sort (CGPA BASED) data are: ";
	student->traverseData();
	
	student->rec(student->head);
/*	string regNumber;
	cout<<"Enter the registration number of student to search his data: ";
	cin>>regNumber;
	Student* s1 = student->search(regNumber);
	if(s1){
		s1->display();
	}
	else{
		cout<<"Student is not present"<<endl;
	}*/
	
//	student->removeFirst();
	
	student->rec_reverse(student->head);
	
	return 0;
}
	
	
	
