// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract StudentData {
    
// Structure to hold student information
struct Student {
    uint id;
    string name;
    uint age;
    string course;
}
// Dynamic array to store student records
Student[] public students;
// Event to emit when a student is added
event StudentAdded(uint id, string name);
// Function to add a new student to the array
function addStudent(uint _id, string memory _name, uint _age, string memory _course) public {
    students.push(Student(_id, _name, _age, _course));
    emit StudentAdded(_id, _name);
}
// Function to get student data by index
function getStudent(uint index) public view returns (uint, string memory, uint, string memory) {
    require(index < students.length, "Index out of range");
    Student memory s = students[index];
    return (s.id, s.name, s.age, s.course);
}
// Function to get total number of students
function getTotalStudents() public view returns (uint) {
    return students.length;
}
// Fallback function to handle unexpected calls or ETH sent to contract
fallback() external payable {
    // Just accept ETH sent to the contract, no logic required
}
// Receive function to accept ETH
    receive() external payable {}
}