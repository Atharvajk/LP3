// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;

contract bank{
    int16 private balance=0;
    string withdrawMessage = "Amount Withdrawn.";
    function depositMoney(int16  val) public{
        balance=balance+val;
    }
    function getBalance() public view returns (int16 ){
        return balance;
    }
    function withdrawMoney(int16 amount) public returns (string memory ){
        require(balance >= amount, "Insufficient balance."); 
        balance=balance-amount;

    }

}