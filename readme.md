<a id="readme-top"></a>

<div align="center">
    <h1>Parsing Functions</h1>
    <p>Compile-time capable string parsing functions.</p>
    <p>
        <a href="">
            <img src="https://img.shields.io/github/last-commit/cdanymar1/Parsing-Functions" alt="last commit">
        </a>
        <a href="https://github.com/cdanymar1/ANSI-Escape-Codes/network/members">
            <img src="https://img.shields.io/github/forks/cdanymar1/Parsing-Functions" alt="forks">
        </a>
        <a href="https://github.com/cdanymar1/Parsing-Functionse/stargazers">
            <img src="https://img.shields.io/github/stars/cdanymar1/Parsing-Functions" alt="stars">
        </a>
        <br>
        <a href="https://github.com/cdanymar1/Parsing-Functions/issues/">
            <img src="https://img.shields.io/github/issues/cdanymar1/Parsing-Functions" alt="open issues">
        </a>
        <a href="https://github.com/cdanymar1/Parsing-Functions/blob/master/LICENSE">
            <img src="https://custom-icon-badges.demolab.com/badge/license-MIT-yellow?logo=law" alt="license">
        </a>
        <img src="https://custom-icon-badges.demolab.com/badge/ISO-23-blue?logo=cplusplus" alt="C++ ISO">
    </p>
    <h4>
        <a href="https://github.com/cdanymar1/Parsing-Functions/tree/master/example">Examples</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/Parsing-Functions/tree/master/docs">Documentation</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/Parsing-Functions/issues">Report Bug</a>
        <span> · </span>
        <a href="https://github.com/cdanymar1/Parsing-Functions/issues">Request Feature</a>
    </h4>
</div>
<br>
<details>
    <summary>Table of Contents</summary>
    <ol>
        <li><a href="#about">About</a></li>
        <li><a href="#getting-started">Getting Started</a></li>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#license">License</a></li>
    </ol>
</details>

## About
This is just a single header file with template functions with compile-time capability to parse strings to other types.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Getting Started
You can just download the single `parse.tpp` file and include it in your project.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Usage
To use this library in your project it must support C++23 features such as `std::vprint_unicode()` and the named standard library module `std`.

```c++
import "parse.tpp"; // or #include

constexpr int val = parse::to<int>(2424);
```

## License
This library is under [MIT license](https://github.com/cdanymar1/Parsing-Functions/blob/master/LICENSE).
<p align="right">(<a href="#readme-top">back to top</a>)</p>
