// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
private:
    struct ITEM {
        T value;
        ITEM* next;
    };
    ITEM* head;
    ITEM* tail;

    ITEM* create(T value) {
        ITEM* item = new ITEM;
        item->value = value;
        item->next = nullptr;
        return item;
    }

public:
    TPQueue() :head(nullptr), tail(nullptr) {}

    void push(T value) {
        if (tail && head) {
            ITEM* tmp = head;
            if (tmp->value.prior < value.prior) {
                tmp = create(data);
                tmp->next = head;
                head = tmp;
            } else {
                while (temp->next) {
                    if (temp->next->value.prior < value.prior) {
                        ITEM* item = create(value);
                        item->next = temp->next;
                        temp->next = item;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
            }
            if (!temp->next) {
                tail->next = create(value);
                tail = tail->next;
            }
        } else {
            head = create(value);
            tail = head;
        }
    }
    T pop() {
        ITEM* temp = head->next;
        T value = head->value;
        delete head;
        head = temp;
        return value;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
