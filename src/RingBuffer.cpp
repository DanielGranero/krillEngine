#include "../include/RingBuffer.h"

namespace KrillEngine{

        // Reset method put tail on head, an full to true
        void RingBuffer::reset(){
            std::lock_guard<std::mutex> lock(mutex_);
            head_ = tail_;
            full_ = false;
        }


        // If full is false and head is equal to tail, we can say buffer is empty
        // Otherwise if full is false is not empty and if full is true but head is not equal  to tail then we have data to read
        bool RingBuffer::empty() const{
            return !full_ && (head_ == tail_);
        }

        // Only check if buffer is full
        bool RingBuffer::full()const{
            return full_;
        }
        
        // Returns max capacity of current buffer
        size_t RingBuffer::capacity()const{
            return max_size_;
        }

        // Returns current size of our buffer (not max size, only the number of items we have wrote but never readed)
        size_t RingBuffer::size()const{
            size_t size = max_size_;
            if(!full_){
                if(head_ >= tail_){
                    size = head_ - tail_;
                }else{
                    size = max_size_ + head_ - tail_;
                }
            }
            return size;
        }

        // Put an item at head position. If buffer is full move tail at the beggining. Move head one position and check if buffer is full
        void RingBuffer::put(float item){
            std::lock_guard<std::mutex>lock(mutex_);
            buf_[head_] = item;
            if(full_){
                tail_ = (tail_ + 1) % max_size_;
            }
            head_ = (head_ + 1) % max_size_;

            full_ = head_ == tail_;
        }

        // Get the item on tail position. As we have read this data, its place is free so buffer is not full. We move tail one position and return the value
        float RingBuffer::get(){
            if(RingBuffer::empty()){
                return float();   
            }

            float item = buf_[tail_];
            full_ = false;
            tail_ = (tail_ + 1) % max_size_;

            return item;
        }
};



