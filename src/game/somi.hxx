#ifndef SOMIGAME_SOMI_HXX
#define SOMIGAME_SOMI_HXX 1

#include "../head.hxx"

/* headers */

#include "../ecos.hxx"

/* content */

namespace somigame { namespace game { /* typedef */

/* somi_t
 * the world singleton
*/
class somi_t : public meta::single_t<somi_t>
{
public: /* codetor */
    inline somi_t() = default;
public: /* getters */
    [[nodiscard]] inline constexpr
    auto get_ent() const
    { return this->ent; }
    template<typename...com_t>
    [[nodiscard]] inline constexpr
    auto&&get_com() const
    { return ecos::ecs.get<com_t...>(this->get_ent()); }
public: /* setters */
public: /* vetters */
    [[nodiscard]] inline
    bool vet_ent(bool valid = TRUTH)
    { return ecos::ecs.valid(this->get_ent()) == valid; }
    template<typename...com_t>
    [[nodiscard]] inline
    bool vet_com() const
    { return ecos::ecs.all_of<com_t...>(this->get_ent()); }
public: /* actions */
    bool init();
    bool quit();
public: /* datadef */
    ent_t ent = entt::null;
};

} } /* typedef */

#endif/*SOMIGAME_SOMI_HXX*/
