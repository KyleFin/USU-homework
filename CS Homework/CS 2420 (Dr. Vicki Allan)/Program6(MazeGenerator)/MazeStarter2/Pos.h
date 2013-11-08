#ifndef POS_H
#define POS_H

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Pos {
public: 
  Pos(int r=0, int c=0) { row = r; col = c;};
  int row,col;
  bool equals(Pos & p){
	  return row==p.row && col==p.col;
  }
  bool operator==(Pos & p){
	  return row==p.row && col==p.col;
  }
  string toString(){
    stringstream out;
    out << "Pos [" << row << "," << col << "]";
    return out.str();
  };
};

#endif