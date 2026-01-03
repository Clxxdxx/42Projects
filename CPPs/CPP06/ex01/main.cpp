#include "Serializer.hpp"
#include <iostream>
int main()
{
    Data data;

    data.number = 42;
    data.text = "Hello 42";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    cout << "Original pointer:     " << originalPtr << endl;
    cout << "Deserialized pointer: " << deserializedPtr << endl;

    return 0;
}