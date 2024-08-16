import "parse.tpp";

int main()
{
    std::cout << (parse::to<int>("424") == 424);
    return 0;
}
