/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:04:54 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/26 15:12:36 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Create a Data structure to serialize
    Data data;
    data.value = 42;
    data.name = "Test Data";
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "Value: " << data.value << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Address: " << &data << std::endl;
    
    // Serialize the Data pointer to uintptr_t
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\nSerialized: " << raw << std::endl;
    
    // Deserialize back to Data pointer
    Data* deserializedData = Serializer::deserialize(raw);
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Value: " << deserializedData->value << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    
    // Verify they point to the same object
    if (&data == deserializedData) {
        std::cout << "\n✓ Serialization/Deserialization successful!" << std::endl;
    } else {
        std::cout << "\n✗ Serialization/Deserialization failed!" << std::endl;
    }
    
    return 0;
}