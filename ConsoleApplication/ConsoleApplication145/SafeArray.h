//#include "ArrayIndexOutOfBoundsException.h"

template <typename CType>
class SafeArray { 
public: 
    // 建構函式 
    SafeArray(int); 
    // 解構函式 
    ~SafeArray();
 
    CType get(int); 
    void set(int, CType);
 
    int length;
private:
    CType *_array; 

    bool isSafe(int i); 
};

// 動態配置陣列
template <typename CType>
SafeArray<CType>::SafeArray(int len) {
    length = len;
    _array = new CType[length];
}

// 測試是否超出陣列長度
template <typename CType>
bool SafeArray<CType>::isSafe(int i) {
    // 
    if(i >= length || i < 0) {
        return false;
    } 
    else {
        return true;
    }
}

// 取得陣列元素值
template <typename CType>
CType SafeArray<CType>::get(int i) {
    if(isSafe(i)) {
        return _array[i]; 
    }
    else {
        // 存取超過陣列長度，丟出例外 
        throw ArrayIndexOutOfBoundsException(i); 
    }
}

// 設定陣列元素值
template <typename CType>
void SafeArray<CType>::set(int i, CType value) {
    if(isSafe(i)) {
        _array[i] = value;
    }
    else {
        // 存取超過陣列長度，丟出例外
        throw ArrayIndexOutOfBoundsException(i); 
    }
}

// 刪除動態配置的資源
template <typename CType>
SafeArray<CType>::~SafeArray() {
    delete [] _array;
}