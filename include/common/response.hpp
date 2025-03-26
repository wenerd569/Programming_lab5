#pragma once

#include <memory>
#include <utility>

template <typename T>
class Response{
public:
    enum Code{
        OK,
        NULL_RESULT,
        ERROR_ELEMENT_NOT_FOUND,
        CANT_SAVE_DATA,
        INDEX_OUT_OF_RANGE_EXEPTION,
        FAIL,
    };
private:
    Code statusCode;
    std::unique_ptr<T> data;
public:
    static Response success(T value);
    static Response failure(Code errorCode);

    Response(Response&& other) noexcept = default;
    Response& operator=(Response&& other) noexcept;
    ~Response() = default;

    const T& getData() const;
    Code getStatusCode() const;
private:
    Response(Code error);
    Response(std::unique_ptr<T> ptr, Code error);
};


template <>
class Response<void>{
public:
    enum Code{
        OK,
        NULL_RESULT,
        ERROR_ELEMENT_NOT_FOUND,
        CANT_SAVE_DATA,
        INDEX_OUT_OF_RANGE_EXEPTION,
        FAIL,
    };
private:
    Code statusCode;
public:
    static Response success();
    static Response failure(Code errorCode);

    Response(Response&& other) noexcept = default;
    Response& operator=(Response&& other) noexcept = default;
    ~Response() = default;

    Code getStatusCode() const;
private:
    Response(Code error);
};







template <typename T>
Response<T> Response<T>::success(T value) {
    return Response<T>(std::make_unique<T>(std::move(value)), OK);
}

template <typename T>
Response<T> Response<T>::failure(Code errorCode) {
    return Response<T>(errorCode);
}

template<typename T>
const T& Response<T>::getData() const { return *data; }

template<typename T>
Response<T>::Code Response<T>::getStatusCode() const { return statusCode; }


template<typename T>
Response<T>::Response(std::unique_ptr<T> ptr, Response<T>::Code statusCode) : data{std::move(ptr)}, statusCode{statusCode} {}


template<typename T>
Response<T>::Response(Response<T>::Code statusCode) : statusCode{statusCode} {}