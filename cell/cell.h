#ifndef INCLUDED_CELL_
#define INCLUDED_CELL_

#include <cstddef>
#include <vector>

#define SIZE 4

class cell
{
    size_t d_x;
    size_t d_y;
    float d_reward;
    bool d_border;
    bool d_start;

    float *d_QValue;
    public:
        cell();
        cell(size_t width, size_t height, char character);
        cell(const cell& other);    //copy
        cell(cell&& tmp);   //move
        cell &operator=(cell const &tmp);
        ~cell();
        
        size_t getWidth() const;
        size_t getHeight() const;
        float getReward() const;
        bool getStart() const;
        bool getBorder() const;
        float* getQValue() const;

        void setQValue(float* newQValue);

        void print() const;

    private:
        void setWidth(size_t newWidth);
        void setHeight(size_t newHeight); 
        void setStart(bool status);
        void setBorder(bool status);
        
        void swap(cell &other);
};
        
#endif
