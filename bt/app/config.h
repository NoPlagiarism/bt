#pragma once

#include <string>
#include <vector>
#include <chrono>
#include "browser.h"

namespace bt {

    struct custom_browser_config {
        std::string long_sys_name;
        std::string name;
        std::string cmd;
        std::string arg;
    };

    enum class firefox_container_mode {
        off = 0,
        bt = 1,
        ouic = 2
    };

    class config {
    public:
        config();

        std::string get_iid();

        void set_theme(const std::string& id);
        std::string get_theme();

        void set_picker_enabled(bool enabled);
        bool get_picker_enabled();
        void set_picker_hotkey(const std::string& hotkey);
        std::string get_picker_hotkey();
        void set_open_method(const std::string& method_name);
        std::string get_open_method();

        void set_fallback(const std::string& long_sys_name);
        std::string get_fallback_long_sys_name();

        int get_popularity(const std::string& long_sys_name);
        void set_popularity(const std::string& long_sys_name, int value);

        bool get_log_rule_hits();
        void set_log_rule_hits(bool on);

        firefox_container_mode get_firefox_container_mode();
        void set_firefox_container_mode(firefox_container_mode mode);

        // --- browser/instance
        
        void save_browsers(std::vector<std::shared_ptr<browser>> browsers);

        std::vector<std::shared_ptr<browser>> load_browsers();

        // -- to remove:

        /*std::vector<std::string> load_rules(const std::string& long_sys_name);
        void save_rules(const std::string& long_sys_name, const std::vector<std::string>& rules);

        void save_custom(const std::string& long_sys_name,
            const std::string& name,
            const std::string& cmd,
            const std::string& arg);

        std::vector<custom_browser_config> load_all_custom();

        void delete_custom(const std::string& long_sys_name);*/

        // ---

        std::chrono::system_clock::time_point get_last_update_check_time();
        void set_last_update_check_time_to_now();


        std::string get_absolute_path();

        // experimental flags
        std::string get_flag(const std::string& name);

        // conversion functions
        static std::string firefox_container_mode_to_string(firefox_container_mode mode);
        static firefox_container_mode to_firefox_container_mode(const std::string& name);


        // global instance
        static config i;

    private:
        void ensure_instance_id();
        void migrate();
    };
}