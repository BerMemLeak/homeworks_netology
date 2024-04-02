//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>

//проверяемая структура
#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
            : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
            : m_head(new ListNode(static_cast<int>(0))), m_size(0),
              m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

//юнит-тест
TEST_CASE( "PushBack,PushFront,PopBack,PopFront" ) {
    SECTION("PushBack"){
        INFO("Функцию PushBack не работает");
        List list;
        list.PushBack(1);
        REQUIRE(  list.Size() == 1 );
        list.PopBack();
        REQUIRE(list.Empty() == true);
    }
    SECTION("PushFront"){
        INFO("Функцию PushFront не работает");
        List list;
        list.PushFront(1);
        REQUIRE(  list.Size() == 1 );
        list.PopFront();
        REQUIRE(list.Empty() == true);
    }
    SECTION("PopBack"){
        INFO("Функция PopBack() не работает");
        List list;
        list.PushBack(1);
        list.PopBack();
        REQUIRE(list.Empty() == true);
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }

    SECTION("PopFront"){
        INFO("Функцию PopFront не работает");
        List list;
        list.PushFront(1);
        list.PopFront();
        REQUIRE(list.Empty() == true);
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }
    SECTION("all functions"){
        INFO("e2e test failed");
        List list;
        list.PushFront(1);
        list.PushBack(1);
        REQUIRE(list.Size() == 2);
        list.PopFront();
        REQUIRE(list.Size() == 1);
        list.PopBack();
        REQUIRE(list.Size() == 0);
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);

    }
}