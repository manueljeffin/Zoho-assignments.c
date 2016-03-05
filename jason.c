# Zoho-assignments.c
//
//  main.c
//  jason_parsing
//
//  Created by R.M.D. Engineering College on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College. All rights reserved.
//

#include <stdio.h>

struct reference
{
    char *contact_id;
    char *contact_name;
    char *street;
    char *area;
    char *city;
    struct name_details *name_details1;
}*reference_object;
struct name_details
{
    char *contact_person_id;
    char *first_name;
    char *last_name;
    char *email;
}*name_details_object;
