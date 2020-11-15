#include <iostream>
#include "Snitch.h"

Snitch::Snitch(int id) : id_(id)
{
    log("S::ctor");
}

Snitch::Snitch(const Snitch& src) noexcept
: id_(src.id_)
{
    log("S::ctor [copy]");
}

Snitch::Snitch(Snitch&& src) noexcept
: id_(src.id_)
{
    log("S::ctor [move]");
}

Snitch::~Snitch()
{
    log("S::dtor");
}

Snitch& Snitch::operator=(const Snitch& rhs) noexcept
{
    if (logging_enabled_) {
        std::cout << "S::op= [copy], S(" << id_ << ") = S(" <<
                     rhs.id_ << "), " << this << std::endl;
    }
    id_ = rhs.id_;
    return *this;
}

Snitch& Snitch::operator=(Snitch&& rhs) noexcept
{
    if (logging_enabled_) {
        std::cout << "S::op= [move], S(" << id_ << ") = S(" <<
                     rhs.id_ << "), " << this << std::endl;
    }
    id_ = rhs.id_; // std::swap if a resource
    return *this;
}

void Snitch::log(const char *msg)
{
    if (logging_enabled_) {
        std::cout << msg << " " <<
                     id_ << " " << this << std::endl;
    }
}

int Snitch::get_id() const
{
    return id_;
}

void Snitch::disable_log()
{
    Snitch::logging_enabled_ = false;
}

void Snitch::enable_log()
{
    Snitch::logging_enabled_ = true;
}

bool Snitch::logging_enabled_ = true;
