#include "delete-user.h"
#include "unfollow-user.h"
//DELETE ACCOUNT FUNCTION
/*an outer loop will iterate over all the users in the system. When the user intended for deletion is
  matched, then each subsequent user is shifted one place to the left of the user array, which overwrites
  the deleted user.
  The special case is when the user for deletion is the last user in the array. In that case, we don't shift
  any subsequent users (because there are none). Instead we only decrement the total user count, so when we
  iterate over each user in the main function, the last user will be skipped.
*/
void deleteuser(user* a, twitter *system) {

    printf("%s's account has been deleted\n", a -> username);
    printf("next user is automatically activated\n");

    for (int i = 0; i < system -> num_users; i++) {
        for (int j = 0; j <= system -> users[i] .num_following; j++) {
            if (strcmp(a -> username, system -> users[i].following[j]) == 0) {
                unfollow(&system -> users[i], a);
            }
        }
    }

    for (int i = 0; i < system -> num_users; i++) {
        if (strcmp(a ->username, system -> users[i].username) == 0) {

            for(int j = i; j < system -> num_users; j++){
                //strcpy(system -> users[j].username, system -> users[j + 1].username);

                //if deleted user is not last (if it is last just decrement the number of users)
                if (i < system -> num_users - 1) {
                    struct user *a = &system->users[j];
                    struct user *b = &system->users[j + 1];
                    *a = *b;
                }
            }
        }
    }
    system -> num_users--;

}
