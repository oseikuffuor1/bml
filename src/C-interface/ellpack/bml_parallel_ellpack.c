#include "../bml_logger.h"
#include "../bml_parallel.h"
#include "../bml_types.h"
#include "bml_parallel_ellpack.h"
#include "bml_types_ellpack.h"

#include <stdlib.h>
#include <string.h>

/** Gather bml matrix across MPI ranks.
 *
 *  \ingroup parallel_group
 *
 *  \param A The matrix
 */
void
bml_allGatherVParallel_ellpack(
    bml_matrix_ellpack_t * A)
{

    switch (A->matrix_precision)
    {
        case single_real:
            bml_allGatherVParallel_ellpack_single_real(A);
            break;
        case double_real:
            bml_allGatherVParallel_ellpack_double_real(A);
            break;
        case single_complex:
            bml_allGatherVParallel_ellpack_single_complex(A);
            break;
        case double_complex:
            bml_allGatherVParallel_ellpack_double_complex(A);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

#ifdef DO_MPI
void
bml_mpi_type_create_struct_ellpack(
    bml_matrix_ellpack_t * A,
    MPI_Datatype * newtype)
{

    switch (A->matrix_precision)
    {
        case single_real:
            bml_mpi_type_create_struct_ellpack_single_real(A, newtype);
            break;
        case double_real:
            bml_mpi_type_create_struct_ellpack_double_real(A, newtype);
            break;
        case single_complex:
            bml_mpi_type_create_struct_ellpack_single_complex(A, newtype);
            break;
        case double_complex:
            bml_mpi_type_create_struct_ellpack_double_complex(A, newtype);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

void
bml_mpi_send_ellpack(
    bml_matrix_ellpack_t * A,
    const int dst,
    MPI_Comm comm)
{
    switch (A->matrix_precision)
    {
        case single_real:
            bml_mpi_send_ellpack_single_real(A, dst, comm);
            break;
        case double_real:
            bml_mpi_send_ellpack_double_real(A, dst, comm);
            break;
        case single_complex:
            bml_mpi_send_ellpack_single_complex(A, dst, comm);
            break;
        case double_complex:
            bml_mpi_send_ellpack_double_complex(A, dst, comm);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

void
bml_mpi_recv_ellpack(
    bml_matrix_ellpack_t * A,
    const int dst,
    MPI_Comm comm)
{
    switch (A->matrix_precision)
    {
        case single_real:
            bml_mpi_recv_ellpack_single_real(A, dst, comm);
            break;
        case double_real:
            bml_mpi_recv_ellpack_double_real(A, dst, comm);
            break;
        case single_complex:
            bml_mpi_recv_ellpack_single_complex(A, dst, comm);
            break;
        case double_complex:
            bml_mpi_recv_ellpack_double_complex(A, dst, comm);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

bml_matrix_ellpack_t *
bml_mpi_recv_matrix_ellpack(
    bml_matrix_precision_t matrix_precision,
    int N,
    int M,
    const int src,
    MPI_Comm comm)
{
    switch (matrix_precision)
    {
        case single_real:
            return bml_mpi_recv_matrix_ellpack_single_real(N, M, src, comm);
            break;
        case double_real:
            return bml_mpi_recv_matrix_ellpack_double_real(N, M, src, comm);
            break;
        case single_complex:
            return bml_mpi_recv_matrix_ellpack_single_complex(N, M, src,
                                                              comm);
            break;
        case double_complex:
            return bml_mpi_recv_matrix_ellpack_double_complex(N, M, src,
                                                              comm);
            break;
        default:
            LOG_ERROR("unknown precision\n");
            break;
    }
}

#endif
