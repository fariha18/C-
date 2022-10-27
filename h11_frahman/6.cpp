void add(string s){
if(size == capacity){
grow();
}
students[size++] = s;
}

void grow(){
capacity = 2 * capacity + 1;
string *temp = new string [capacity];
for(int i = 0; i<size; i++){
temp[i] = students [i];
}
delete [] students;
students = temp;
}

ostream& operator<<(ostream& out, const Course &c) {
out << "Course - " << c.name << ":\n";
for(int i=0; i<c.size; i++){
  out << c.students[i] << "\n";
}
out << "\n";
return out;
}
