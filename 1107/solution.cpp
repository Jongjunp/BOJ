#include <iostream>
using namespace std;

int main() {
    int targ_channel;
    cin >> targ_channel;
    int num_malfunct_buttons;
    int channels[500001] = {0};
    bool buttons[10] = {true};
    cin >> num_malfunct_buttons;
    for (int i=0; i<num_malfunct_buttons; i++) {
        int malfunct_button;
        cin >> malfunct_button;
        buttons[malfunct_button] = false;
    }
    
}