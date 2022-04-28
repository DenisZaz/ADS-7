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
    ITEM* head, * tail;
    ITEM* create(T value) {
        ITEM* item = new ITEM;
        item->value = value;
        item->next = nullptr;
        return item;
    }
 public:
    TPQueue: head(nullptr), tail(nullptr){}

    T pop() {
        ITEM* item = head->next;
        T value = head->value;
        delete head;
        head = temp;
        return value;
    }

    void push(T sym) {
        if (tail && head) {
            ITEM* temp = head;
            if (temp->sym.prior < sym.prior) {
                temp = create(sym);
                temp->next = head;
                head = temp;
            } else {
                while (temp->next) {
                    if (temp->next->sym.prior < sym.prior) {
                        ITEM* t = create(sym);
                        t->next = temp->next;
                        temp->next = t;
                        break;
                    } else {
                        temp = temp->next;
                      }
                }
              }
            if (!temp->next) {
                tail->next = create(sym);
                tail = tail->next;
            }
        } else {
            head = create(sym);
            tail = head;
          }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
