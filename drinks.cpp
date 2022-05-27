#include <iostream>

using namespace std;

enum Flavor { Original, Vanilla, Malt };
enum Size { Small, Medium, Large, ExtraLarge };

struct Shake {
  Flavor flavor;
  Size size;
};

namespace en {
  string getFlavor(int f) {
  switch(f){
    case 0:
      return "Original";
      break;
    case 1:
      return "Vanilla";
      break;
    case 2:
      return "Malt";
      break;
    default:
      return "Invalid Flavor";
  }
}

// Small, Medium, Large, ExtraLarge

string getSize(int f) {
  switch(f){
    case 0:
      return "Small";
      break;
    case 1:
      return "Medium";
      break;
    case 2:
      return "Large";
      break;
    case 3:
      return "ExtraLarge";
      break;
    default:
      return "Invalid Size";
  }
}
}

class Drinks {
  public:
    Drinks(int maxSize = 12);
    ~Drinks();
    void addDrink(Shake s);
    string getFlavor(int f);
    string getSize(int f);
    void toOutput();
  private:
    Shake *drinks;
    int index;
};

Drinks::Drinks(int maxSize) {
  drinks = new Shake[maxSize];
  index =  0;
}

Drinks::~Drinks() {
  delete[] drinks;
}

void Drinks::addDrink(Shake s) {
  drinks[index] = s;
  index += 1;
}


void Drinks::toOutput() {
  string s = "";
  for (int i=0; i < index; i++) {
    cout << "Order: " << i << endl << "Flavor " << en::getFlavor(drinks[i].flavor) << endl << "Size " << en::getSize(drinks[i].size) << endl;
  }
}

int main () {
  Shake shake1;
  shake1.flavor = Original;
  shake1.size = ExtraLarge;
  
  Shake shake2;
  shake2.flavor = Malt;
  shake2.size = Medium;

  Shake shake3;
  shake3.flavor = Original;
  shake3.size = Large;
  
  Shake shake4;
  shake4.flavor = Vanilla;
  shake4.size = Large;
  
  Drinks* drinks = new Drinks();
  (*drinks).addDrink(shake1);
  (*drinks).addDrink(shake2);
  (*drinks).addDrink(shake3);
  (*drinks).addDrink(shake4);
  
  (*drinks).toOutput();
  
  delete drinks;
  
  return 0;
}