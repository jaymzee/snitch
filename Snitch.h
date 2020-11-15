#ifndef SNITCH_H
#define SNITCH_H

class Snitch {
private:
    int id_;
protected:
    static bool logging_enabled_;
    void log(const char *msg);
public:
    Snitch(int id = 0);
    Snitch(const Snitch& src) noexcept;
    Snitch(Snitch&& src) noexcept;
    ~Snitch();
    Snitch& operator=(const Snitch& src) noexcept;
    Snitch& operator=(Snitch&& src) noexcept;
    int get_id() const;
    static void disable_log();
    static void enable_log();
};

#endif
