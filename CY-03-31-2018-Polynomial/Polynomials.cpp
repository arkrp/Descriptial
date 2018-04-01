//POLYNOMIAL IMPLEMENTATION FILE--[draft #1] CHRISTOPHER YANG; MARCH 31; CS 2 FINAL PROJECT

#include "Polynomials.hpp"

istream &operator>>(istream &input, Poly &polyin){
    cout << "Input Polynomial: Enter in form  a + b x^i + c x^j + d x^k ..." << endl;
    
    polyin.coefficients.clear();
    
    double coeff = 0; //The coefficient we are obtaining from input
    int sign = 1; //Specifies whether the coefficient positive or negative
    char temp = '\0'; //Used to get characters such as '+' or '-'
    int power = 0; //The power of x with which the coefficient is multiplied
    //int prevpower = 0;
    bool successdone = false; //True if successfully processed the entire input; breaks the loop
    
    int vecpos = 0; //The position we are
    
    while (successdone == false){
        input >> coeff; //Get coefficient
        if (input.peek() != '\n') //If not at end of input
            temp = input.get(); //Get the char at the current location (after coefficient)
        if(input.peek() == 'x') //If the char next to temp is an "x"
        {
            //Move two spaces
            cin >> temp;
            cin >> temp;
            if(temp == '^'){
                //Get the power of x
                input >> power;
                
                //Expand the vector to accomodate new coefficient (expand until reaches the power of x)
                while (vecpos <= power){
                    polyin.coefficients.push_back(0);
                    vecpos ++;
                }
                //prevpower = power;
                polyin.coefficients[vecpos - 1] = sign*coeff;
            }
            
            if(input.peek() == '\n') //End of input
            {
                successdone = true;
            }
            else {
                //Move to the next character after the space
                cin >> temp;
                
                //Determine the sign of the next coefficient, or if the input has ended
                if(input.peek() == ' '){
                    if(temp == '+'){
                        sign = 1;
                    }
                    else if(temp == '-'){
                        sign = -1;
                        input.peek();
                    }
                    else {
                        input.clear(ios::failbit);
                        return input;
                    }
                }
                else //Invalid input
                {
                    input.clear(ios::failbit);
                    return input;
                }
            }
        }
        else if (vecpos == 0) //When the coefficient is not multiplied to x AND we are on the first coefficient. The "a" in a + bx + cx^2 + ... In this case, the negative sign, if exists, is automatically attached.
        {
            //Add this coefficient (constant term) to the vector
            polyin.coefficients.push_back(coeff);
            
            //Increment the vector position
            vecpos ++;
            
            //Determine the sign of the next coefficient, or if the input has ended
            
            if(input.peek() == '\n') //End of input
            {
                successdone = true;
            }
            else {
                if(temp == ' '){
                    //Move to the next character after the space
                    cin >> temp;
                    
                    if(temp == '+'){
                        sign = 1;
                    }
                    else if(temp == '-'){
                        sign = -1;
                    }
                    else {
                        //If there is no + or - after a space, something is wrong.
                        input.clear( ios::failbit );
                        return input;
                    }
                }
                else //Invalid input
                {
                    input.clear( ios::failbit );
                    return input;
                }
            }
        }
        else //Then invalid input
        {
            input.clear( ios::failbit );
            return input;
        }
    }
    return input;
}
