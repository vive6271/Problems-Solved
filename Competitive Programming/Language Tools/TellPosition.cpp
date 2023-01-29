#include<bits/stdc++.h>
using namespace std;

class Student{
public:
  string name;
  int rollNo;
  int marks;
};

bool compare(Student s1, Student s2){
  if(s1.marks != s2.marks){
    return s1.marks > s2.marks;
  }
  return s1.rollNo < s2.rollNo;
}
int main(){
  int n;
  cin >> n;
  vector<Student> v(n);
  for(int i = 0; i < n; i++){
    int c1, c2, c3;
    cin >> v[i].name >>  c1 >> c2 >> c3;
    v[i].rollNo = (i+1);
    v[i].marks = (c1+c2+c3);
  }
  sort(v.begin(), v.end(), compare);
  for(int i = 0; i < n; i++){
    cout << (i+1) << " " << v[i].name << endl;
  }
	return 0;
}


/* Better
#include<bits/stdc++.h>
using namespace std;

class Student{
public:
  string name;
  int rollNo;
  int marks;
};

bool compare(Student s1, Student s2){
  if(s1.marks != s2.marks){
    return s1.marks > s2.marks;
  }
  return s1.rollNo < s2.rollNo;
}
int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<Student> v(n);
  for(int i = 0; i < n; i++){
    int c1, c2, c3;
    cin >> v[i].name >>  c1 >> c2 >> c3;
    v[i].rollNo = (i+1);
    v[i].marks = (c1+c2+c3);
  }
  sort(v.begin(), v.end(), compare);
  for(int i = 0; i < n; i++){
    cout << (i+1) << " " << v[i].name << '\n';
  }
	return 0;
}
*/
