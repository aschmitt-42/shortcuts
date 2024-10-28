#ifndef SS_HPP
# define SS_HPP

# include <iostream>

class ss
{ 
    private :

    public :
        ss();
        ~ss();
        ss(const ss &other);
        ss& operator=(const ss &other);
};

// std::ostream& operator<<(std::ostream& os, const ss& other);

#endif 
