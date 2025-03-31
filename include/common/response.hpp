#pragma once

#include <memory>
#include <utility>

/**
 * @brief Класс ответа от сервера
 * Может содержать либо возвращаемые данные и код OK либо код ошибки
 * @tparam T
 */
template<typename T>
class Response {
public:
    /**
     * @brief Коды ответа
     */
    enum Code {
        OK,
        NULL_RESULT,
        ELEMENT_NOT_FOUND,
        CANT_SAVE_DATA,
        INDEX_OUT_OF_RANGE,
        FAIL,
    };

private:
    Code statusCode;
    T data;

public:
    /**
     * @brief Фабричный метод создания ответа без ошибки
     * Отвечат за инвариант класса
     * @param value
     * @return Response
     */
    static Response success (T value);
    /**
     * @brief Фабричный метод создания ответа c ошибкой
     * Отвечат за инвариант класса
     * @param errorCode
     * @return Response
     */
    static Response failure (Code errorCode);

    Response(Response &&other) noexcept = default;
    Response &operator=(Response &&other) noexcept;
    ~Response() = default;

    const T &getData () const &;
    Code getStatusCode () const;

private:
    Response(Code error);
    Response(T ptr, Code error);
};

/**
 * @brief Класс ответа от сервера без данных
 * Нужно реализовывать отдельно поскольку он не хранит данные
 * @tparam
 */
template<>
class Response<void> {
public:
    enum Code {
        OK,
        NULL_RESULT,
        ELEMENT_NOT_FOUND,
        CANT_SAVE_DATA,
        INDEX_OUT_OF_RANGE,
        FAIL,
    };

private:
    Code statusCode;

public:
    static Response success ();
    static Response failure (Code errorCode);

    Response(Response &&other) noexcept = default;
    Response &operator=(Response &&other) noexcept = default;
    ~Response() = default;

    Code getStatusCode () const;

private:
    Response(Code error);
};

template<typename T>
Response<T> Response<T>::success(T value)
{
    return Response<T>(std::move(value), OK);
}

template<typename T>
Response<T> Response<T>::failure(Code errorCode)
{
    return Response<T>(errorCode);
}

template<typename T>
const T &Response<T>::getData() const &
{
    return data;
}

template<typename T>
Response<T>::Code Response<T>::getStatusCode() const
{
    return statusCode;
}

template<typename T>
Response<T>::Response(T data, Response<T>::Code statusCode)
    : data { std::move(data) }, statusCode { statusCode }
{
}

template<typename T>
Response<T>::Response(Response<T>::Code statusCode) : statusCode { statusCode }
{
}