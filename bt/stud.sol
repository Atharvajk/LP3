// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract StudentData {
    event Log(string func, address sender, uint value, bytes data);
  struct Student{
    uint stud_id;
    string name;
    string department;
  }
  
  Student[] students;

  function addStudent(uint id , string memory stud_name , string memory stud_dept)  public {
    Student memory newStudent = Student(id, stud_name , stud_dept);
    students.push(newStudent);

  }

  function getData(uint id) public view returns(string memory , string memory)
  {
    for(uint i = 0 ; i<students.length ; i++)
    {
      if(students[i].stud_id == id)
      {
        return(students[i].name , students[i].department);
      }
    }
    return ("No Name Found" , "No Department Found");
  }

  function getNum() public view returns(uint)
  {
    return students.length;
  }

  fallback() external payable { 
    students.push(Student(1 , 'ABC' , 'DEF'));
        emit Log("fallback",msg.sender,msg.value,msg.data);

  }
  receive() external payable {
        emit Log("receive",msg.sender,msg.value," ");
   }
}
      