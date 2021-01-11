#ifndef INCLUDED_CELL_
#define INCLUDED_CELL_

#include <cstddef>
#include <vector>

#define SIZE 4

class cell
{
    size_t d_x;
    size_t d_y;
    size_t d_count;
    float d_reward;
    float d_averageReward;
    bool d_border;
    bool d_start;
    char d_character;
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
        float getAverageReward() const;
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
        float setAverageReward(int newAverageReward);

        void swap(cell &other);
};
        
#endif
