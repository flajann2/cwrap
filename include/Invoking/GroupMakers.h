#pragma once
//
//  GroupMakers.h
//  cwrap
//
//  Created by Lisa Lippincott on 8/30/14.
//  Released into the public domain by Lisa Lippincott, 2014.
//


#include "Group modifiers/Returned.h"
#include "Group modifiers/Thrown.h"
#include "Group modifiers/Checked.h"
#include "Groups/In.h"
#include "Groups/Out.h"
#include "Groups/InOut.h"
#include "Groups/NotPassed.h"
#include "Groups/Result.h"

/*
    The namespace cwrap::GroupMakers contains all the names needed for 
    creating the basic pararameter and result groups, gathered together 
    for use in a using-directive.
*/

namespace cwrap
   {
    namespace GroupMakers
       {
        // Groups
            using cwrap::In;
            
            using cwrap::Out;
            using cwrap::OutFailureFlag;
            using cwrap::OutSuccessFlag;
            using cwrap::OutError;
            
            using cwrap::InOut;
            
            using cwrap::NotPassed;
            using cwrap::ExceptionToThrow;
            
            using cwrap::Result;
            using cwrap::NoResult;
            using cwrap::FailureFlagResult;
            using cwrap::SuccessFlagResult;
            using cwrap::ErrorResult;
            
        // Modifiers
            using cwrap::FailsWhen;
            using cwrap::SucceedsWhen;
            using cwrap::FailsWhenTrue;
            using cwrap::FailsWhenFalse;
            
            using cwrap::Returned;
            using cwrap::NotReturned;
            
            using cwrap::Thrown;
            using cwrap::NotThrown;
       }
   }

