/* include/n/j.h
**
** This file is in the public domain.
*/
  /** Noun semantics.
  **/
#if 0
  ++  bane  ,@tas                                         ::  battery name
  ++  bash  ,@uvH                                         ::  label hash
  ++  bosh  ,@uvH                                         ::  battery hash
  ++  batt  ,*                                            ::  battery
  ++  calf                                                ::  
    $:  jax=,@ud                                          ::  hot core index
        hap=(map ,@ud ,@ud)                               ::  axis/hot arm index
        lab=path                                          ::  label as path
        jit=*                                             ::  arbitrary data
    ==                                                    ::
  ++  calx  (trel calf (pair bash cope) club)             ::  cached by battery
  ++  clog  (pair cope (map batt club))                   ::  label record
  ++  club  (pair corp (map term nock))                   ::  battery pattern
  ++  cope  (trel bane axis (each bash noun))             ::  core pattern
  ++  core  ,*
  ++  corp  (each core batt)                              ::  parent or static
  ++  dash  (map bash clog)                               ::  jet system
#endif

  /** Data structures.
  ***
  *** All of these are transient structures allocated with malloc.
  **/
    /* u3j_harm: jet arm.
    */
      typedef struct _u3j_harm {
        c3_c*             fcs_c;               //  `.axe` or name
        u3_noun           (*fun_f)(u3_noun);   //  compute or 0 / semitransfer
        // c3_o           (*val_f)(u3_noun);   //  validate or 0 / retain
        c3_o              ice;                 //  perfect (don't test)
        c3_o              tot;                 //  total (never punts)
        c3_o              liv;                 //  live (enabled)
        c3_l              axe_l;               //  computed/discovered axis
        struct _u3j_core* cop_u;               //  containing core
      } u3j_harm;

    /* u3j_core: driver definition.
    */
      typedef struct _u3j_core {
        c3_c*             cos_c;        //  control string
        struct _u3j_harm* arm_u;        //  blank-terminated static list
        struct _u3j_core* dev_u;        //  blank-terminated static list
        struct _u3j_core* par_u;        //  dynamic parent pointer 
        c3_l              axe_l;        //  axis to parent
        c3_l              jax_l;        //  index in global dashboard
      } u3j_core;

    /* u3e_dash, u3_Dash, u3D: jet dashboard singleton
    */
      typedef struct _u3e_dash {
        u3j_core* dev_u;              //  null-terminated static list
        c3_l      len_l;              //  dynamic array length
        c3_l      all_l;              //  allocated length
        u3j_core* ray_u;              //  dynamic array by axis
      } u3j_dash;

    /* u3j_fist: a single step in a fine check.
    */
      typedef struct {
        u3_noun bat;                  //  battery
        u3_noun pax;                  //  parent axis
      } u3j_fist;

    /* u3j_fink: (fine check) enough data to verify a located core.
    */
      typedef struct {
        c3_w    len_w;                //  number of fists
        u3_noun sat;                  //  static noun at end of check
        u3j_fist fis_u[0];            //  fists
      } u3j_fink;

    /* u3j_rite: site of a %fast, used to skip re-mining.
    */
      typedef struct {
        c3_o          own_o;          //  rite owns fink?
        u3_weak       clu;            //  cached product of clue formula
        u3p(u3j_fink) fin_p;          //  fine check
      } u3j_rite;

    /* u3j_site: site of a kick (nock 9), used to cache call target.
    */
      struct _u3n_prog;
      typedef struct {
        u3p(struct _u3n_prog) pog_p;  //  program for formula
        u3_noun       axe;            //  axis
        u3_weak       bat;            //  battery (for verification)
        u3_weak       loc;            //  location (for reaming)
        c3_o          jet_o;          //  have jet driver?
        c3_o          fon_o;          //  site owns fink?
        u3_weak       lab;            //  label (for tracing)
        u3j_core*     cop_u;          //  jet core
        u3j_harm*     ham_u;          //  jet arm
        u3p(u3j_fink) fin_p;          //  fine check
      } u3j_site;

  /** Globals.
  **/
    /* u3_Dash: jet dashboard.
    */
      extern u3j_dash u3j_Dash;
#     define u3D u3j_Dash

    /**  Functions.
    **/
      /* u3j_boot(): initialize jet system.
      */
        void
        u3j_boot(void);

      /* u3j_clear(): clear jet table to re-register.
      */
        void
        u3j_clear(void);

      /* u3j_cook():
      **
      **   Execute hook from core, call site cached by arbitrary c string
      */
        u3_noun
        u3j_cook(const c3_c* key_c,
                 u3_noun     cor,
                 const c3_c* tam_c);

      /* u3j_hook():
      **
      **   Execute hook from core. 
      */
        u3_noun
        u3j_hook(u3_noun     cor,
                 const c3_c* tam_c);

      /* u3j_soft():
      **
      **   Execute hook from core, without jet.
      */
        u3_noun
        u3j_soft(u3_noun     cor,
                 const c3_c* tam_c);

      /* u3j_kick(): try to kick by jet.  If no kick, produce u3_none.
      **
      ** `axe` is RETAINED by the caller; `cor` is RETAINED iff there 
      ** is no kick, TRANSFERRED if one.
      */
        u3_weak
        u3j_kick(u3_noun cor, u3_noun axe);

      /* u3j_kink(): kick either by jet or by nock.
      */
        u3_noun
        u3j_kink(u3_noun cor,
                   u3_noun axe);

      /* u3j_mine(): register core for jets.
      */
        void
        u3j_mine(u3_noun clu,
                   u3_noun cor);

      /* u3j_ream(): refresh after restoring from checkpoint.
      */
        void
        u3j_ream(void);

      /* u3j_reap(): promote jet state.  RETAINS.
      */
        void
        u3j_reap(u3p(u3h_root) cod_p, u3p(u3h_root) war_p, u3p(u3h_root) han_p);

      /* u3j_rite_mine(): mine cor with clu, using u3j_rite for caching
      */
        void
        u3j_rite_mine(u3j_rite* rit_u, u3_noun clu, u3_noun cor);

      /* u3j_rite_copy(): copy rite references from src_u to dst_u,
      **                  losing old references if los_o is yes
      */
        void
        u3j_rite_copy(u3j_rite* dst_u, u3j_rite* src_u, c3_o los_o);

      /* u3j_site_copy(): copy site references from src_u to dst_u,
      **                  losing old references if los_o is yes
      */
        void
        u3j_site_copy(u3j_site* dst_u, u3j_site* src_u, c3_o los_o);

      /* u3j_site_ream(): refresh u3j_site after restoring from checkpoint
      */
        void
        u3j_site_ream(u3j_site* sit_u);

      /* u3j_site_kick(): kick a core with a u3j_site cache.
       */
        u3_weak
        u3j_site_kick(u3_noun cor, u3j_site* sit_u);

      /* u3j_gate_prep(): prepare a locally cached gate to call repeatedly.
       */
        void
        u3j_gate_prep(u3j_site* sit_u, u3_noun cor);

      /* u3j_gate_slam(): slam a site prepared by u3j_gate_find() with sample.
       */
        u3_noun
        u3j_gate_slam(u3j_site* sit_u, u3_noun sam);

      /* u3j_gate_lose(): clean up site prepared by u3j_gate_find().
       */
        void
        u3j_gate_lose(u3j_site* sit_u);

      /* u3j_rite_mark(): mark u3j_rite for gc.
      */
        c3_w
        u3j_rite_mark(u3j_rite* rit_u);

      /* u3j_rite_lose(): lose references of u3j_rite (but do not free).
      */
        void
        u3j_rite_lose(u3j_rite* rit_u);

      /* u3j_site_lose(): lose references of u3j_site (but do not free).
      */
        void
        u3j_site_lose(u3j_site* sit_u);

      /* u3j_site_mark(): mark u3j_site for gc.
      */
        c3_w
        u3j_site_mark(u3j_site* sit_u);

      /* u3j_mark(): mark jet state for gc.
      */
        c3_w
        u3j_mark(void);

      /* u3j_free(): free jet state.
      */
        void
        u3j_free(void);
