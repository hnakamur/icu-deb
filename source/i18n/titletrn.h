/*
**********************************************************************
*   Copyright (C) 2001, International Business Machines
*   Corporation and others.  All Rights Reserved.
**********************************************************************
*   Date        Name        Description
*   05/24/01    aliu        Creation.
**********************************************************************
*/
#ifndef TITLETRN_H
#define TITLETRN_H

#include "unicode/translit.h"
#include "unicode/locid.h"

U_NAMESPACE_BEGIN

/**
 * A transliterator that converts all letters (as defined by
 * <code>UCharacter.isLetter()</code>) to lower case, except for those
 * letters preceded by non-letters.  The latter are converted to title
 * case using <code>u_totitle()</code>.
 * @author Alan Liu
 */
class U_I18N_API TitlecaseTransliterator : public Transliterator {

    /**
     * ID for this transliterator.
     */
    static const char _ID[];

 public:

    /**
     * Constructs a transliterator.
     */
    TitlecaseTransliterator(const Locale& loc = Locale::getDefault());

    /**
     * Destructor.
     */
    virtual ~TitlecaseTransliterator();

    /**
     * Copy constructor.
     */
    TitlecaseTransliterator(const TitlecaseTransliterator&);

    /**
     * Assignment operator.
     */
    TitlecaseTransliterator& operator=(const TitlecaseTransliterator&);

    /**
     * Transliterator API.
     */
    Transliterator* clone(void) const;

 protected:

    /**
     * Implements {@link Transliterator#handleTransliterate}.
     */
    void handleTransliterate(Replaceable& text, UTransPosition& offset,
                             UBool isIncremental) const;

 public:

    /**
     * Static memory cleanup function.  FOR INTERNAL USE ONLY; DO NOT
     * CALL.
     */
    static void cleanup();
 private:
    Locale loc;
    UChar* buffer;
};

U_NAMESPACE_END

#endif
