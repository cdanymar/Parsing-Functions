/// @file manip.ixx
/// @author Danylo Marchenko (cdanymar)
/// @brief Defines compile-time capable functions for parsing strings to other types.
/// @version 1.0
/// @date 2024-08-14
/// @copyright Copyright (c) 2024
#pragma once

import std;

/// @brief Parse strings to other types.
namespace parse
{
    /// @brief Parsing error report.
    enum class failure
    {
        /// @brief The input string is empty.
        empty_string,

        /// @brief The input string has unparsable value.
        invalid_value,

        /// @brief The input string value is out of underlying type's range.
        out_of_range,

        /// @brief The input string has signed/unsigned mismatch.
        sign_mismatch,

        /// @brief The input string does not satisfy parsing conditions (for user-defined types).
        other
    };


    /// @brief Parses string to another type.
    /// @tparam T Specialized type.
    template <typename T>
    [[nodiscard]] constexpr auto to(std::string_view) -> std::expected<T, failure> = delete;

    /// @brief Unable to parse to void.
    template <>
    [[nodiscard]] constexpr auto to(std::string_view) -> std::expected<void, failure> = delete;

    /// @brief Parses string to a signed integral type.
    /// @tparam Int Signed integral type.
    /// @param text Text to parse.
    /// @return Parsed integer.
    /// @see std::signed_integral
    template <std::signed_integral Int>
    [[nodiscard]] constexpr auto to(const std::string_view text) -> std::expected<Int, failure>
    {
        if (text.empty())
            return std::unexpected(failure::empty_string);

        const std::size_t length = text.length();
        const bool negative = text[0] == '-';

        Int value = 0;
        for (std::size_t i = negative; i < length; i++)
            if (text[i] >= '0' && text[i] <= '9')
            {
                const Int digit = text[i] - '0';

                if (value > (std::numeric_limits<Int>::max() - digit) / 10)
                    return std::unexpected(failure::out_of_range);

                value = value * 10 + (negative ? -digit : digit);
            }
            else if (text[i] != '\'')
                return std::unexpected(failure::invalid_value);

        return value;
    }

    /// @brief Parses string to an unsigned integral type.
    /// @tparam Uint Unsigned integral type.
    /// @param text Text to parse.
    /// @return Parsed integer.
    /// @see std::unsigned_integral
    template <std::unsigned_integral Uint>
    [[nodiscard]] constexpr auto to(const std::string_view text) -> std::expected<Uint, failure>
    {
        if (text.empty())
            return std::unexpected(failure::empty_string);

        if (text[0] == '-')
            return std::unexpected(failure::sign_mismatch);

        const std::size_t length = text.length();

        Uint value = 0;
        for (std::size_t i = 0; i < length; i++)
            if (text[i] >= '0' && text[i] <= '9')
            {
                const Uint digit = text[i] - '0';

                if (value > (std::numeric_limits<Uint>::max() - digit) / 10)
                    return std::unexpected(failure::out_of_range);

                value = value * 10 + digit;
            }
            else if (text[i] != '\'')
                return std::unexpected(failure::invalid_value);

        return value;
    }

    /// @brief Parses string to a floating point type.
    /// @warning Has not been tested with the new extended floating point types.
    /// @tparam Float Floating point type.
    /// @param text Text to parse.
    /// @return Parsed float.
    /// @see std::floating_point
    template <std::floating_point Float>
    [[nodiscard]] constexpr auto to(const std::string_view text) -> std::expected<Float, failure>
    {
        constexpr std::intmax_t noDot = -1;

        if (text.empty())
            return std::unexpected(failure::empty_string);

        // if (text == "nan")
        //     return std::nan()

        const std::size_t length = text.length();
        const bool negative = text[0] == '-';

        Float value = 0;
        std::intmax_t dot = noDot;
        std::size_t pos = negative;

        for (std::size_t i = negative; i < length; i++)
            if (text[i] >= '0' && text[i] <= '9')
            {
                value = value * 10 + text[i] - '0';
                pos++;
            }
            else if (text[i] == '.')
            {
                if (dot != noDot)
                    return std::unexpected(failure::invalid_value);

                dot = i;
            }
            else if (text[i] != '\'')
                return std::unexpected(failure::invalid_value);

        if (dot != noDot)
        {
            Float exp = 10;
            for (std::size_t i = 1; i < pos - dot; i++)
                exp *= 10;

            value /= exp;
        }

        return negative ? -value : value;
    }

    /// @brief Parses string to boolean.
    /// @param text Either 'true' or 'false';
    /// @return Parsed value, if any.
    [[nodiscard]] constexpr auto to(const std::string_view text) -> std::expected<bool, failure>
    {
        if (text.empty())
            return std::unexpected(failure::empty_string);

        if (text == "true")
            return true;

        if (text == "false")
            return false;

        return std::unexpected(failure::invalid_value);
    }
}
