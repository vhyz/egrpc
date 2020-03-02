#pragma once

namespace egrpc {

class noncopyable {
   protected:
    noncopyable() = default;

    ~noncopyable() = default;

   private:
    noncopyable(const noncopyable&);

    noncopyable(noncopyable&&);

    noncopyable& operator=(const noncopyable&);

    noncopyable& operator=(noncopyable&&);
};

};  // namespace egrpc