namespace String_Basic{
    // Convert int to string
    template <typename T>
    string to_str(T str){
        stringstream stream;
        stream << str;
        return stream.str();
    }

    // Convert string to int
    template <typename T>
    int to_int(T num){
        int val;
        stringstream stream;
        stream << num;
        stream >> val;
        return val;
    }

    // To Lower
    string ToLower(string s){
        for (int i = 0; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    // To Upper
    string ToUpper(string s){
        for (int i = 0; i < s.size(); ++i) {
            s[i] = toupper(s[i]);
        }
        return s;
    }
}using namespace String_Basic;
