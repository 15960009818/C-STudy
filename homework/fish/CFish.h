#ifndef CFISH_H
#define CFISH_H

class Fish {
public:
    Fish(int weight);
    int getWeight() const;
    void grow();

private:
    int weight;
};

#endif // CFISH_H

