#include <memory>
#include <mutex>
namespace KrillEngine{
    class RingBuffer{
    public:
        // RingBuffer constructor, this class constructs itself
        explicit RingBuffer(size_t size) :
            buf_(std::unique_ptr<float[]>(new float[size])),
            max_size_(size)
        {}

        // Put method
        void put(float item);

        // Get method
        float get();

        // Reset method
        void reset();

        // Empty method
        bool empty() const;

        // Full method
        bool full() const;

        // Capacity method
        size_t capacity() const;

        // Size method
        size_t size() const;

    private:
        // mutex to make read/write operations thread safe
        std::mutex mutex_;

        // ring buffer of floats
        std::unique_ptr<float[]> buf_;

        // first position: used to read
        size_t head_ = 0;

        // last position: used to write
        size_t tail_ = 0;

        // max size of buffer
        const size_t max_size_;

        // boolean: is full -> true | is not -> false
        bool full_ = 0;
    };
};