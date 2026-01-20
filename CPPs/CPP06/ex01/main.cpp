/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:18:19 by clalopez          #+#    #+#             */
/*   Updated: 2026/01/09 12:16:58 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
int main()
{
    Data data;

    data.number = 72633;
    data.text = "Claudio";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    cout << "Original pointer: " << originalPtr << endl;
    cout << "Memory raw: " << raw << endl;
    cout << "Deserialized pointer: " << deserializedPtr << endl;

    return 0;
}