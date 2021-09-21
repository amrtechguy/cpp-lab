            std::cout << "[ ";
            for(const auto &key_value: record)
            {
                std::cout << key_value.first << ": " << key_value.second << ", "; 
            }
            std::cout << "]";