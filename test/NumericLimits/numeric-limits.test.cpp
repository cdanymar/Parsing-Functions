import std;
import "parse.tpp";

auto main() -> int
{
    using parse::to;

    static_assert(to<signed char>("-128") == -128);
    static_assert(to<signed char>("127") == 127);
    static_assert(to<signed char>("256").has_value() == false);

    static_assert(to<unsigned char>("255") == 255);
    static_assert(to<unsigned char>("-128").has_value() == false);

    static_assert(to<signed short int>("-32'768") == -32'768);
    static_assert(to<signed short int>("32'767") == 32'767);
    static_assert(to<signed short int>("65'535").has_value() == false);

    static_assert(to<unsigned short int>("65'535") == 65'535);
    static_assert(to<unsigned short int>("-32768").has_value() == false);

    static_assert(to<signed int>("-2'147'483'648") == -2'147'483'648);
    static_assert(to<signed int>("2'147'483'647") == 2'147'483'647);
    static_assert(to<signed int>("4'294'967'295").has_value() == false);

    static_assert(to<unsigned int>("4'294'967'295") == 4'294'967'295);
    static_assert(to<unsigned int>("-2'147'483'648").has_value() == false);

    static_assert(to<signed long int>("-2'147'483'648") == -2'147'483'648);
    static_assert(to<signed long int>("2'147'483'647") == 2'147'483'647);
    static_assert(to<signed long int>("4'294'967'295").has_value() == false);

    static_assert(to<unsigned long int>("4'294'967'295") == 4'294'967'295);
    static_assert(to<unsigned long int>("-2'147'483'648").has_value() == false);

    static_assert(to<signed long long int>("-9'223'372'036'854'775'807") == -9'223'372'036'854'775'807LL);
    static_assert(to<signed long long int>("9'223'372'036'854'775'807") == 9'223'372'036'854'775'807);
    static_assert(to<signed long long int>("18'446'744'073'709'551'615").has_value() == false);

    static_assert(to<unsigned long long int>("18'446'744'073'709'551'615") == 18'446'744'073'709'551'615);
    static_assert(to<unsigned long long int>("-9'223'372'036'854'775'808").has_value() == false);

    static_assert(to<float>("3.1415").has_value());
    static_assert(to<double>("3.14159998").has_value());
    static_assert(to<long double>("-10231.34").has_value());
}
