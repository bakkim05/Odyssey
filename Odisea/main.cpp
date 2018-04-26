#include "Hash/HashFunction.h"

using namespace std;

int main() {
    int index ;

    HashFunction hashObject;

    index = hashObject.Hash("Hello");
    cout << "index: " << index << endl;

}