#pragma once

template <class Type> class Set {
private:
    struct Element {
        Type value;
        Element* next;
        Element(Type _value) : value(_value), next(nullptr) {}
    };

    Element* head;
    int count;

public:
    Set() : head(nullptr), count(0) {}

    Set(Type value) : head(nullptr), count(0) { this->push(value); }

    Set(const Set& s) :head(nullptr), count(0) {
        Element* temp = s.head;
        while (temp) {
            this->push(temp->value);
            temp = temp->next;
        }
    }

    ~Set() {}

    bool push(Type value) {
        Element* newElement = new Element(value);

        if (this->head == nullptr) {
            this->head = newElement;
            this->count++;
            return true;
        }
        else {
            if (this->isMember(value)) {
                return false;
            }
            else {
                Element* temp = this->head;

                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newElement;
                this->count++;
                return true;
            }
        }
    }

    bool pop(Type value) {
        if (!this->isMember(value)) {
            return false;
        }
        else {
            Element* temp = this->head;

            if (temp->value == value) {
                this->head = temp->next;
                delete temp;
                this->count--;
                return true;
            }
            else {
                while (temp->next && temp->next->value != value) {
                    temp = temp->next;
                }
                if (temp->next) {
                    Element* toDelete = temp->next;

                    temp->next = toDelete->next;
                    delete toDelete;
                    this->count--;
                    return true;
                }
                return false;
            }
        }
    }

    void empty() {
        while (this->head) {
            Element* temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
        this->count = 0;
    }

    bool isMember(Type value) const {
        Element* temp = this->head;

        while (temp) {
            if (temp->value == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Type get(int x) const {
        if (x >= count) {
            std::cout << "Tried to get value exceeding count\n";
            return Type();
        }
        Element* temp = this->head;
        for (int i = 0; i < x; i++) {
            temp = temp->next;
        }
        return temp->value;
    }

    int getSize() const { return this->count; }

    template <typename T>
    Set& operator=(const Set<T>& r) {
        this->empty();

        Element* temp = r.head;
        while (temp) {
            this->push(temp->value);
            temp = temp->next;
        }
        return *this;
    }

    template <typename T> friend std::ostream& operator<<(std::ostream& out, const Set<T>& s);
    template <typename T> friend Set<T> operator+(const Set<T>& l, const Set<T>& r);
    template <typename T> friend Set<T> operator-(const Set<T>& l, const Set<T>& r);
    template <typename T> friend Set<T> operator*(const Set<T>& l, const Set<T>& r);
    template <typename T> friend Set<T>& operator+=(Set<T>& l, const Set<T>& r);
    template <typename T> friend Set<T>& operator-=(Set<T>& l, const Set<T>& r);
    template <typename T> friend Set<T>& operator*=(Set<T>& l, const Set<T>& r);
};


template <typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& s) {
    typename Set<T>::Element* temp = s.head;
    while (temp) {
        out << temp->value << "\n";
        temp = temp->next;
    }
    return out;
}

template <typename T> Set<T> operator+(const Set<T>& l, const Set<T>& r) {
    Set<T> newSet(l);
    typename Set<T>::Element* temp = r.head;

    while (temp) {
        newSet.push(temp->value);
        temp = temp->next;
    }
    return newSet;
}

template <typename T> Set<T> operator-(const Set<T>& l, const Set<T>& r) {
    Set<T> newSet(l);
    typename Set<T>::Element* temp = r.head;

	while (temp) {
		newSet.pop(temp->value);
		temp = temp->next;
	}
	return newSet;
}

template <typename T> Set<T> operator*(const Set<T>& l, const Set<T>& r) {
    Set<T> temp;

    for (int i = 0; i < l.getSize(); i++) {
        T lValue = l.get(i);
        for (int j = 0; j < r.getSize(); j++) {
            T rValue = r.get(j);
            if (lValue == rValue) {
                temp.push(lValue);
                break;
            }
        }
    }
    return temp;
}

template <typename T> inline Set<T>& operator+=(Set<T>& l, const Set<T>& r) {
    l = l + r;
    return l;
}

template <typename T> inline Set<T>& operator-=(Set<T>& l, const Set<T>& r) {
    l = l - r;
    return l;
}

template <typename T> inline Set<T>& operator*=(Set<T>& l, const Set<T>& r) {
    l = l * r;
    return l;
}
