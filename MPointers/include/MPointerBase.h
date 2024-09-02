#ifndef MPOINTERBASE_H
#define MPOINTERBASE_H

class MPointerBase {
public:
    virtual ~MPointerBase() = default;
    virtual int getId() const = 0;
};

#endif // MPOINTERBASE_H